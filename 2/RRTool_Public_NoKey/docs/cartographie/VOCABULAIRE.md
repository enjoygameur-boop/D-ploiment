# Vocabulaire

Termes maison du corpus. Definition deduite du texte, jamais inventee.
Un terme sans definition suffisante porte INCONNU.

## Licence
Jeton a€” Chaine base64 de 105 octets : magie, version, empreinte, dates, serie, signature. JOURNAL entree licence.
RRL1 a€” Magie de quatre octets en tete du jeton. Meme entree.
licence.dat a€” Fichier livre a l acheteur, contenu du jeton. docs/INSTALLATION_CLIENT.md:10.
Joker a€” Empreinte ("FF"*16) valable sur toute machine. docs/PROCEDURE_LICENCES.md:19.Empreinte a€” MachineGuid tronque a 16, 32 caracteres hexadecimaux. JOURNAL entree licence.
MachineGuid a€” Identifiant machine lu au registre. docs/DEFAUTS.md:11.
bind.dat a€” Fichier de liaison, non signe. docs/DEFAUTS.md:8.
Bind a€” Valeur registre doublant bind.dat sous HKLM\SOFTWARE\Dreww. JOURNAL entree D01 attenue.
Seen a€” Valeur registre de l anti-recul. JOURNAL entree licence.
lic_bind a€” Fonction de liaison, reverifie la signature. JOURNAL entree A3 termine.
lic_days_left a€” Fonction des jours restants. JOURNAL entree D05 ferme.
kMsg a€” Table des messages de refus. JOURNAL entree A3 termine.
Code de refus a€” Entier 1 a 10 nommant une cause de refus. docs/INSTALLATION_CLIENT.md:46-54.
Anti-recul a€” Refus quand l horloge recule de plus de 24 h. JOURNAL entree licence.

## Distribution
Payload a€” Dossier d extraction des binaires embarques. BUILD.md section Masquerade.
Masquage a€” Copie du lanceur et de l overlay sous un nom benin. Meme section.
Veil a€” Demande de masquage noyau, refusee par defaut, SYSTEM\WmPort\Veil = 0. Meme section.
AIO a€” Executable tout-en-un RobRunAIO.exe. BUILD.md.
Colis a€” Dossier remis a l acheteur apres paiement. docs/INSTALLATION_CLIENT.md:10.

## Transport et noyau
WmPort a€” Nom du pilote noyau. BUILD.md section Build the driver.
SmxRing a€” Nom de transport anterieur, encore employe par _scratch/SINGLE_BUILD.md. OBSOLETE.
IOCTL a€” Requete de controle envoyee au pilote. README.md.
Snapshot a€” Copie publiee d un releve de monde, sous verrou. README.md.
Roster a€” Ensemble des joueurs decouverts. README.md.
dlog a€” Journal de decouverte, ecrit dans discovery.log. rr_game.c:34, cite par sonde.
hklogf a€” Journal des entrees clavier, serialise. rr_esp.c:94, cite par sonde.
robrun_runtime.txt a€” Cache d indices de decouverte. rr_game.c:58.
status.log a€” Etat publie que le lanceur surveille. aio_launcher.c:94, cite par sonde.

## Rendu
w2s a€” Passage d un point monde aux pixels ecran. README.md.
Cham a€” Mesh de reference rasterise puis texture. README.md.
Rig a€” Hierarchie d ossements. README.md.
Pose gate a€” Confirmation bornee d une pose brusque. rr_pose_gate.h.
MIX a€” Hachage de cache de rendu, un champ par appel. _scratch/HANDOFF_aim_suivant.txt Â§2.
Occupants a€” Joueurs presents dans un vehicule. rr_esp.c:757, cite par sonde.
hidden_in_object a€” Joueur cache dans un objet. rr_game.c:5371, cite par sonde.

## Visee
knocked_out a€” Nom runtime de la phase au sol, en minuscules. _scratch/HANDOFF_aim_suivant.txt Â§3.
civil, citizen a€” Role civil, exclu de la visee. rr_game.c:1598, cite par sonde.
relationship a€” Drapeaux d appartenance CLAN et POLICE. rr_game.h:31.
aa_stick a€” Reglage plafonnant l assouplissement du gain. _scratch/HANDOFF_suivant.txt Â§6.
aa_switch_margin a€” Marge qu un rival doit battre pour prendre le verrou. Corps de rr_aim_pick.
aa_smooth a€” Facteur de lissage de l asservissement. _scratch/_probe_site.txt.
aa_aim_cal a€” Calibration, 100 fois les counts par pixel de reference. README.md.
Lead a€” Avance de prediction sur une cible mobile. _scratch/HANDOFF_suivant.txt Â§6.
LOS CLEAR, BLOCKED, UNKNOWN a€” Trois etats de ligne de vue. README.md.

## Exploitation
fast_scan a€” Revelation du contenu des contenants par ecriture d un flottant. _scratch/MAINTENANCE_fast_scan.txt.
get, set, dly1-2-3 a€” Cinq sites RVA patches par fast_scan. Meme fichier, section A3.
INST a€” Marqueur de journal de l installation des patchs. Meme fichier, section D3.
g_views_updater a€” Pointeur global de l updater, expose par rr_game_views_updater(). Meme fichier, section A2.

## Interface et reglages
RCDATA 101 a€” Ressource du menu embarquee dans l executable. BUILD.md section Menu edits.
BR_SETTINGS, BR_Config a€” Schema de reglages, liste X avec defaut et bornes. menu_bridge.h.
selftest a€” Auto-test hors ligne, vingt-deux cas. BUILD.md section Check the overlay offline.
reattach a€” Redemarrage de l overlay par le lanceur faute de donnees. BUILD.md section Menu wait and reattach.
menu_delay, attach_timeout, reattach_attempts a€” Cles de RobRunAIO.ini. BUILD.md tableau des reglages.

## Conventions de depot
Dxx a€” Identifiant de defaut. docs/DEFAUTS.md.
Rxx a€” Identifiant de risque. docs/RISQUES.md.
OK_knock, bad_knock, bak_knock a€” Suffixes de copies de sauvegarde de source. _scratch/HANDOFF_aim_suivant.txt Â§1.
SINGLE_BUILD a€” Guide d une tentative tout-en-un, marque obsolete. _scratch/SINGLE_BUILD.md.

## Termes non couverts
Les termes suivants apparaissent sans definition suffisante : INCONNU.
Veil en execution, forme exacte du blob ECS1, structure de bind.dat, contenu de discovery.log.
