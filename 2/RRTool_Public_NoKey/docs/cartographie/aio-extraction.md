# Extraction du payload

## But
Deballer les binaires embarques dans un dossier d execution.
## Ou ca vit
- 2_src_port/aio_launcher.c, non lu
- BUILD.md section all-in-one launcher et section Masquerade
- aio_launcher.c:1243-1266, cites par sonde

## Comment ca marche
FAIT a€” Le payload est deballe dans payload/ a cote du lanceur, ou dans %LOCALAPPDATA%\RRAIO\payload si ce dossier est en lecture seule. BUILD.md section all-in-one launcher.
FAIT a€” L overlay ecrit CoreRR.cfg et ses journaux la. Un CoreRR.cfg a cote du lanceur est copie une fois. Meme section.
FAIT a€” En mode masque, l overlay et WebView2Loader.dll sont copies dans %TEMP% avec CoreRR.cfg une fois. BUILD.md section Masquerade.
FAIT a€” Les copies precedentes sont supprimees au lancement suivant, par masq.txt et masq_overlay.txt. Meme section.
FAIT a€” Une image de pilote au hachage rejete du 2026-11-07 n est jamais mappee. Section all-in-one launcher.
FAIT a€” Le controle de licence passe avant l extraction, apres creation de fenetre. JOURNAL entree licence.
FAIT a€” La liste du payload est de quatre fichiers, kd2.exe, kernel-mode.sys, RobRunPort.exe, WebView2Loader.dll. _scratch/HANDOFF_suivant.txt Â§8.

## Donnees lues ou ecrites
Ecrit : dossier payload ou %TEMP%, CoreRR.cfg, masq_overlay.txt.

## Reglages
--payload pour un autre dossier.

## Dependances
Ressources embarquees, droits d ecriture.

## Points de rupture
Un dossier en lecture seule bascule sur %LOCALAPPDATA%, sans avertissement visible.
Un overlay vivant verrouille la destination, echec 0x20, ancien port rejoue. _scratch/HANDOFF_aim_suivant.txt Â§5.
Sans purge, le lancement reutilise l ancien payload. Meme section.

## Inconnus
Ordre exact des extractions. Gestion des erreurs d ecriture.

## Sources
BUILD.md sections all-in-one launcher et Masquerade. JOURNAL entree licence. _scratch/HANDOFF_aim_suivant.txt Â§5, Â§8.
