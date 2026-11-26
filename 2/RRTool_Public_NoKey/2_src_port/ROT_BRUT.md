# ROT BRUT — dossier technique

Etat documente : commit 7a9eb38
"rage: aimbot verrouille par ecriture rot, restauration sensibilite, cible collante"

Ce fichier decrit le mode rot tel qu'il fonctionnait et tel qu'il a ete valide.
Il ne decrit pas les tentatives ulterieures (onglet Rage, compensation de
depassement, integration sur erreur ecran), abandonnees et conservees dans un
stash git.

## 1. Perimetre

Le mode rot est un actionneur alternatif de l'aim assist. Les filtres, la
selection de cible, la prediction, le FOV et la touche sont communs aux deux
modes. Seule la sortie change :

- mode souris : deplacement de curseur, invisible pour l'antitriche ;
- mode rot : ecriture de l'angle de vue en memoire, instantane mais visible.

Les deux modes ne tournent jamais ensemble. La bascule se fait par `aa_mode`.

## 2. Principe

Le jeu calcule la direction de tir depuis `rot`. La camera recopie cette
direction en `cam+0x1C`, c'est une copie derivee : ecrire la camera serait
ecrase, on ecrit donc `rot`.

Trois invariants rendent l'ecriture tenable :

1. la sensibilite est mise a zero pendant toute la tenue, sinon le modele de
   rotation du jeu combat nos valeurs et la camera entre en resonance ;
2. le point de visee est pris sous l'os, pas sur l'os, pour compenser la
   parallaxe entre l'oeil et le canon ;
3. la cible est collante sur plusieurs frames, sinon la selection saute et la
   consigne avec elle.

Le quaternion `rot+0x20` n'est pas ecrit : le jeu le recalcule depuis `rot`.
Verifie par sonde, `yq` suit exactement pi moins le yaw precedent.

## 3. Chaine d'appel

    aa_tick (rr_esp.c)
      -> lecture de la touche et de aa_mode
      -> rr_aim_pick  (selection, filtres, FOV, LOS, prediction)
      -> si mode rot : calcul yaw/pitch, ecretage, rr_rage_write
      -> sinon : rr_aim_step + aa_move_mouse
      -> au relachement : rr_rage_release

`rr_rage_write` et `rr_rage_release` vivent dans rr_rage.c et sont les seules
a toucher `rot` et `sens`. Le reste du code ne connait que des angles.

## 4. Adresses

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

Toute lecture passe par les accesseurs `PL()`, `rr_u64`, `rr_f32`, sous
`__try/__except` pour les zones instables.

## 5. Algorithme par tick

    held = (rot || aa_on) && GetAsyncKeyState(aa_key)
    si !held :
        locked_addr = 0
        rr_rage_release()
        sortie

    pick = rr_aim_pick(...)          // cible collante, filtres, FOV, LOS
    si pas de cible : sortie

    aimpt = tete de la cible
    aimpt.y -= 0.06                  // sous l'os

    dx = aimpt.x - org.x
    dy = aimpt.y - org.y
    dz = aimpt.z - org.z
    len = sqrt(dx*dx + dy*dy + dz*dz)
    si len <= 0.5 : sortie

    yaw   = atan2f(dx, dz)
    pitch = -asinf(dy / len)

    // ecretage angulaire
    dyaw  = normalise(yaw - cy)      // ramene dans [-pi, pi]
    dpit  = pitch - cp
    dyaw  = clamp(dyaw, -lim, +lim)
    dpit  = clamp(dpit, -lim, +lim)
    yaw   = cy + dyaw
    pitch = cp + dpit

    ecrire rot+0x10 = yaw
    ecrire rot+0x14 = pitch
    ecrire sens+0x10 = 0
    ecrire sens+0x14 = 0

`lim` derive de `rage_max_speed`. A zero, le plafond est neutralise et le pas
n'est plus borne.

## 6. Restauration

`rr_rage_release` remet les sensibilites d'origine, memorisees a l'appui dans
`g_by` et `g_bp`, uniquement si `rage_restore` est actif. Sans cette
restauration, la souris reste morte apres le premier appui.

## 7. Configuration

Le mode rot partage la configuration de l'aim assist :

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
| rage_nospread | neutralisation de la dispersion |

## 8. Ce qui a ete mesure

- Le tir lit `rot`, pas la camera : la camera n'est qu'une copie.
- Le jeu recalcule le quaternion, rien a ecrire.
- Le jeu reecrit `rot` depuis son propre etat : une ecriture isolee tient
  quelques centiemes de radian puis derive.
- Ecrire a 68 Hz fait resonner la camera. Une ecriture unique par appui se pose
  a 0,0015 rad de la consigne et reste stable.
- La camera depasse d'environ 0,065 rad dans le sens du mouvement.
- `g_rcam.fwd` n'est pas une mesure fiable de la camera.
- `pick.dx` / `pick.dy` sont rafraichis a basse frequence, pas a chaque tick.
- L'ecart residuel en regime stable est de l'ordre de 3 a 6 degres.

## 9. Limites connues

- Oscillation si la cadence d'ecriture depasse la vitesse de stabilisation.
- Derive verticale continue d'environ 0,05 rad/s, aggravee par le recul.
- Ecart de parallaxe non nul : la balle ne part pas de la camera.
- La sensibilite a zero est une signature reconnaissable.
- Le mode ecrit en memoire, contrairement au mode souris : c'est ce qui a valu
  le blocage de compte de 1824 jours.

## 10. Protocole de test

1. fermer l'overlay et le jeu n'est pas necessaire ;
2. lancer `1_run\RobRunPort.exe` directement, pas via l'AIO ;
3. ecrire les cles dans `1_run\CoreRR.cfg` et non dans `payload` ;
4. activer rot, touche N pour un test sans recul ;
5. une tenue de trois secondes sur cible immobile ;
6. lire `rage.log` et l'extrait `rot: CAP` de `hotkeys.log`.

Sondes utiles :

    Select-String -Path '...\1_run\hotkeys.log' -Pattern 'rot: CAP' |
      Select-Object -Last 30 | ForEach-Object { $_.Line }

    Get-Content '...\1_run\rage.log' -Tail 40

## 11. Pieges rencontres

- `payload\CoreRR.cfg` est lu par le lanceur, `1_run\CoreRR.cfg` par l'exe
  lance directement. Se tromper de fichier fait tester une config morte.
- Un `.obj` perime se lie a la place du fichier recompile : supprimer les
  `.obj` avant tout build de controle.
- Un binaire sans la sonde attendue se reconnait par un `Contains` sur l'exe.
- `Alt-F4` plante la machine, fermer par Ctrl+Fin.
- Les here-strings PowerShell produisent des LF, les sources sont en CRLF.
- En .NET, `$` ne matche pas devant CRLF : pas d'ancre en fin de ligne.
- Une comparaison de flottants avec `!=` est toujours vraie sur des valeurs
  recalculees : comparer des pixels entiers.
- Les macros de la table de reglages cassent si une barre oblique est suivie
  d'un espace.

## 12. Reprise

Le travail abandonne (compensation de depassement, integration sur erreur
ecran, anti-emballement) est dans le stash git `essai rot precision abandonne`.
