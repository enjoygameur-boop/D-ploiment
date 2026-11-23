# Remplacement du menu sans rebuild complet

## But
Remplacer la ressource 101 d un binaire existant sans relancer la chaine de build.

## Ou ca vit
- 2_src_port/update_menu.ps1, non lu
- BUILD.md section Menu edits

## Comment ca marche
FAIT a€” Le menu est charge depuis la ressource 101 RCDATA, pas depuis un fichier libre. BUILD.md section Menu edits.
FAIT a€” Le script remplace la ressource, verifie la relecture octet par octet, garde RobRunPort.exe.orig et reconstruit le lanceur. Meme section.
FAIT a€” Appel par .\update_menu.ps1 -Rebuild. Meme section.
FAIT a€” Le chemin normal reste build_port.bat puis build_aio.bat. Meme section.
DECISION 2026-11-23 a€” update_menu.ps1 reste disponible pour patcher sans rebuild. Meme section.

## Donnees lues ou ecrites
Lit : menu.html, RobRunPort.exe. Ecrit : ressource 101 du binaire, RobRunPort.exe.orig, RobRunAIO.exe.

## Reglages
Option -Rebuild : enchaine sur la reconstruction du lanceur.

## Dependances
menu.html. rc.exe. RobRunPort.exe existant.

## Points de rupture
Un binaire patche sans rebuild peut diverger des sources : le menu ne correspond plus a app.rc.
La verification octet par octet porte sur la relecture, pas sur la compilation.
Le binaire patche n est pas couvert par la comparaison de hachage du protocole de livraison.

## Inconnus
Contenu de update_menu.ps1 : methode d injection, controles reels.

## Sources
BUILD.md section Menu edits.
## Ancres de ligne
- menu.html:401, controle de menu, ressource remplacee
- BUILD.md, section Menu edits, sans numero de ligne
