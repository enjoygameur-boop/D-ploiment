# Schema des reglages

## But
Definir nom, defaut, minimum et maximum de chaque reglage, et produire la configuration persistee.
## Ou ca vit
- 2_src_port/menu_bridge.h, 3525 octets
- menu_bridge.h:28, 45, 48-49, exemples de lignes

## Comment ca marche
FAIT a€” La liste X(nom, defaut, min, max) porte les reglages. menu_bridge.h:28, 45, 48-49.
FAIT a€” show_police vaut 1 par defaut, aa_target_police 0, aa_ignore_knocked 0, aa_ignore_civil 0. Memes lignes.
FAIT a€” aa_target_police passe a 1 sur decision du 2026-11-22. JOURNAL entree 2026-11-22.
FAIT a€” Chaque champ est melange dans le hachage de rendu par MIX. rr_esp.c:757, cite par sonde.
FAIT a€” Un bloc de defauts ecrit written.<champ> = 1 et la condition de rechargement exige loaded.<champ> == 1. _scratch/HANDOFF_aim_suivant.txt Â§2.
FAIT a€” L aller-retour de configuration est teste, y compris l import de reglages herites. selftest.log:2-7.
FAIT a€” La configuration s ecrit dans CoreRR.cfg a cote de l executable. README section Controls and settings.

## Donnees lues ou ecrites
Ecrit : CoreRR.cfg. Lit : CoreRR.cfg.

## Reglages
Toute la liste X.

## Dependances
menu_bridge.h, rr_esp.c, menu.html.

## Points de rupture
Un champ ajoute sans MIX fige l affichage. _scratch/HANDOFF_aim_suivant.txt Â§2.
Un champ ajoute sans entree de defaut n est pas recharge. Meme section.
Le fichier vit dans le dossier de travail, donc en %TEMP% en mode masque.

## Inconnus
Bornes reelles de chaque reglage. Format exact du fichier.

## Sources
menu_bridge.h:28, 45, 48-49. rr_esp.c:757, cite par sonde. selftest.log:2-7. README section Controls and settings. _scratch/HANDOFF_aim_suivant.txt Â§2.
