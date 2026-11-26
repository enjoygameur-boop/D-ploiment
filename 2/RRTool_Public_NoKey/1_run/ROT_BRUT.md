# ROT BRUT — dossier technique

Objectif unique : que le mode rot ne provoque pas de ban immediat.

Etat documente : commit 7a9eb38, plus constats releves apres remise a zero.
Tout ce qui augmente la surface d'ecriture sans servir l'objectif est hors
perimetre et documente comme tel.

## 1. Perimetre

Le mode rot est un actionneur alternatif de l'aim assist. Filtres, selection,
prediction, FOV et touche sont communs. Seule la sortie change :

- mode souris : deplacement de curseur, invisible pour l'antitriche ;
- mode rot : ecriture de l'angle de vue en memoire, instantane mais visible.

Hors perimetre, conserve mais neutralise :

- `rage_nospread` : la dispersion n'est plus ecrite dans le chemin rot. Deux
  entiers reecrits a chaque tick pour un gain de signature nul. Cle conservee,
  entree de menu conservee, defaut `0`.

Intention non tenue par le code actuel : les deux modes ne devraient jamais
tourner ensemble. Le thread rot est lance inconditionnellement et `aa_tick`
ignore `aa_mode`, donc aujourd'hui les deux ecrivent en meme temps. A corriger.

## 2. Ce qu'un serveur peut voir, classe

1. Des ecritures memoire a periode fixe. Aujourd'hui 600 a 700 par seconde.
2. Une sensibilite a zero pendant toute la tenue, puis restauree.
3. Un identifiant de cible reecrit en boucle.
4. Une dispersion constante a chaque tick.
5. Une rotation non humaine : saut instantane, angle constant, repetition
   parfaite d'un appui a l'autre.
6. Un etat laisse modifie apres le relachement, souris morte comprise.
7. Un motif stable : memes offsets, meme ordre, meme cadence.

L'objectif porte sur les points 1, 3, 4, 6 et 7. Les points 2 et 5 sont traites
en dernier parce qu'ils touchent au comportement et pas au volume.

## 3. Principe

Le jeu calcule la direction de tir depuis `rot`. La camera recopie cette
direction en `cam+0x1C`, c'est une copie derivee : ecrire la camera serait
ecrase, on ecrit donc `rot`.

Trois invariants rendent l'ecriture tenable :

1. la sensibilite est neutralisee pendant la tenue, sinon le modele de rotation
   du jeu combat nos valeurs et la camera entre en resonance ;
2. le point de visee est pris sous l'os, pas sur l'os, pour compenser la
   parallaxe entre l'oeil et le canon ;
3. la cible est collante sur plusieurs frames, sinon la selection saute et la
   consigne avec elle.

Le quaternion `rot+0x20` n'est pas ecrit : le jeu le recalcule depuis `rot`.

## 4. Chaine d'appel

    aa_tick (rr_esp.c)
      -> lecture de la touche et de aa_mode
      -> rr_aim_pick  (selection, filtres, FOV, LOS, prediction)
      -> si mode rot : calcul yaw/pitch, ecretage, ecriture
      -> sinon : rr_aim_step + aa_move_mouse
      -> au relachement : chemin unique de restauration

Toutes les ecritures de `rot` et `sens` passent par un seul point d'entree et
un seul point de sortie dans rr_rage.c. Le reste du code ne connait que des
angles.

## 5. Adresses

Toutes les bases sont resolues une fois par session, pas a chaque tick.

| Role | Chaine |
|---|---|
| scene | game_scene_debug -> game |
| updater | game+0x58 |
| battle | updater+0x70 |
| joueur local | rr_local_player() |
| table des cibles | battle+0x40 |
| modele de cible | battle+0x198 |
| personnage | battle+0x1F8 / battle+0x200 |
| position | char+0x10 |
| tete | char+0x220 |
| rot yaw | rot+0x10 |
| rot pitch | rot+0x14 |
| quaternion | rot+0x20 |
| direction camera | cam+0x1C |
| sensibilite x/y | sens+0x10, sens+0x14 |

Toute lecture passe par `PL()`, `rr_u64`, `rr_f32`, sous `__try/__except`.

## 6. Defauts mesures du code actuel

Ce paragraphe est la cible du travail.

- Thread rot lance inconditionnellement, `aa_mode` ignore par `aa_tick` : les
  deux modes ecrivent ensemble.
- 600 a 700 ecritures par seconde. Par tick : `rot+0x10`, `rot+0x14`,
  `sens+0x10`, `sens+0x14`, `cid`, plus deux entiers de dispersion.
- La sensibilite est reecrite a chaque tick alors qu'elle ne change pas.
- L'identifiant de cible est reecrit a chaque tick.
- Le relachement est perdu sur trois sorties anticipees : pas de cible,
  distance inferieure a 0,5, ecretage. La souris reste morte.
- La consigne est un instantane fige a l'appui. Le residu de 3 a 6 degres vient
  d'une lecture vieille de 100 ms.
- `game_scene_debug` rend 0 en boucle et `rr_local_player()` rend 0, alors que
  le snapshot trouve camera et joueurs. Sans scene, aucune ecriture : a reparer
  avant tout levier de discretion.

## 7. Algorithme cible par tick

    held = touche tenue && aa_mode == rot
    si !held : chemin unique de restauration, sortie

    pick = rr_aim_pick(...)
    si pas de cible : restauration, sortie

    si cid != g_cid : ecrire cid, g_cid = cid      // une fois par changement
    si !g_sens_zero : ecrire sens = 0, g_sens_zero = 1   // une fois par appui

    dx = px cible - px curseur       // entiers, pas de != sur des flottants
    dy = py cible - py curseur
    si |dx| <= aa_rot_dead_px et |dy| <= aa_rot_dead_px : sortie, rien ecrit

    si tick - g_last_write < intervalle effectif : sortie
    intervalle effectif = aa_rot_write_ms * (1 +- jitter)

    calcul yaw/pitch, ecretage, ecriture rot+0x10 et rot+0x14
    g_last_write = tick

Regles :

- jamais d'ecriture si l'ecart est sous le seuil mort ;
- jamais d'ecriture plus souvent que l'intervalle ;
- aucun offset reecrit s'il n'a pas change ;
- la dispersion n'est pas ecrite.

## 8. Restauration

Un seul chemin de restauration, appele sur les quatre sorties :

1. touche relachee ;
2. menu ouvert ;
3. perte de focus / Alt+Tab ;
4. arret du processus ou perte du processus cible.

Il restaure la sensibilite memorisee a l'appui et remet le drapeau `g_sens_zero`
a 0. Sans ce chemin unique, la souris reste morte. Le compteur d'ecritures est
journalise a chaque restauration pour mesurer le volume reel.

## 9. Configuration

Cles communes avec l'aim assist, inchangees :

| Cle | Effet |
|---|---|
| aa_mode | bascule souris / rot |
| aa_key | touche de tenue |
| aa_fov_px | rayon de selection a l'ecran |
| aa_bone | os vise |
| aa_los_on | filtre de ligne de vue |
| aa_dist | portee maximale |
| aa_ignore_civil | ignore les civils |
| aa_ignore_knocked | ignore les au sol |
| aa_target_clan | cible les membres de clan |
| aa_target_police | cible la police |
| aa_switch_margin | hysteresis de changement de cible |
| aa_smooth | lissage, alimente aussi la prediction |
| aa_stick | duree du verrou |
| aa_aim_cal | calibration du point de visee |
| rage_max_speed | plafond angulaire par tick |
| rage_restore | restauration de la sensibilite |
| rage_nospread | dispersion — hors perimetre, defaut 0 |

Nouvelles cles, bornees :

| Cle | Defaut | Min | Max | Effet |
|---|---|---|---|---|
| aa_rot_dead_px | 3 | 1 | 40 | seuil mort, en pixels ecran |
| aa_rot_write_ms | 50 | 16 | 250 | intervalle minimal entre deux ecritures |
| aa_rot_jitter_pct | 8 | 0 | 20 | amplitude du jitter sur l'intervalle |
| aa_rot_cid | 1 | 0 | 1 | ecrire l'identifiant de cible |
| aa_rot_sens_hold | 1 | 0 | 1 | neutraliser la sensibilite pendant la tenue |

## 10. Mesures de reference

- Cadence reelle : 600 a 700 ecritures par seconde. La valeur de 68 Hz ecrite
  dans une version anterieure de ce dossier est fausse.
- Residu en regime stable : 3 a 6 degres, cause identifiee, lecture vieille de
  100 ms. Ce n'est pas une propriete du modele de rotation.
- Depassement de la camera d'environ 0,065 rad dans le sens du mouvement.
- `g_rcam.fwd` n'est pas une mesure fiable de la camera.

Cibles a mesurer apres patch : ecritures par seconde, ecritures sur trois
secondes de cible alignee, ecritures apres relachement, groupement.

## 11. Protocole de test

1. `taskkill RobRunPort.exe` et `RobRunAIO.exe` ;
2. suppression des `.obj`, `build_port.bat`, `build_aio.bat`, les deux en
   `BUILD_OK` ;
3. verification de la sonde par `Contains` sur l'exe ;
4. `1_run\RobRunPort.exe` lance directement ;
5. cles ecrites dans `1_run\CoreRR.cfg`, cheat ferme, jamais dans `payload` ;
6. rot actif, touche N pour les tests sans recul ;
7. tenue de trois secondes sur cible immobile, puis cible mobile ;
8. releve de `rage.log` et des lignes `WR` et `RELEASE` de `hotkeys.log` ;
9. verification de la souris apres chaque sortie.

Sondes :

    Select-String -Path '...\1_run\hotkeys.log' -Pattern 'RELEASE|WR ' |
      Select-Object -Last 30 | ForEach-Object { $_.Line }

    Get-Content '...\1_run\rage.log' -Tail 40

## 12. Criteres d'acceptation

- Ecritures par seconde en baisse d'au moins un ordre de grandeur.
- Zero ecriture sur trois secondes de cible alignee.
- Aucune ecriture apres relachement, sur les quatre sorties.
- Souris rendue a chaque relachement.
- Aucune oscillation de camera en regime stable.
- Mode souris inchange, verifie par un test dedie.
- Groupement conserve : secondaire, eliminatoire en cas d'effondrement.

## 13. Pieges

- `payload\CoreRR.cfg` est lu par le lanceur, `1_run\CoreRR.cfg` par l'exe lance
  directement.
- Le fichier de config est reecrit a chaque sortie depuis la memoire : toute
  edition faite pendant que l'overlay tourne est perdue.
- La touche se change dans le menu, pas dans le fichier.
- Un `.obj` perime se lie a la place du fichier recompile.
- Un binaire sans la sonde se reconnait par un `Contains` sur l'exe.
- `Alt-F4` plante la machine, fermer par Ctrl+Fin.
- Les here-strings PowerShell produisent des LF, les sources sont en CRLF.
- Une comparaison de flottants avec `!=` est toujours vraie.
- Les macros de la table de reglages cassent si une barre oblique est suivie
  d'un espace.

## 14. Reste a faire

1. Reparer `game_scene_debug` / `rr_local_player` : sans scene, aucune ecriture.
2. Porter le relachement sur un chemin unique et couvrir les quatre sorties.
3. Rendre `aa_mode` effectif : les deux modes ne doivent plus ecrire ensemble.
4. Supprimer l'ecriture de sensibilite par tick, passer a une ecriture par appui.
5. Supprimer l'ecriture de `cid` par tick, une ecriture par changement.
6. Sortir la dispersion du chemin d'ecriture.
7. Introduire seuil mort, intervalle, jitter.
8. Point et axe de visee, puis cinematique, puis variance.
9. Tableau avant/apres et surfaces de detection restantes.