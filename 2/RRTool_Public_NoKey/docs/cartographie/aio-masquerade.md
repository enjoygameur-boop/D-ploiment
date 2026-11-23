# Masquage du lanceur et de l overlay

## But
Faire tourner le produit sous un nom benin, hors du dossier livre.
## Ou ca vit
- BUILD.md section Masquerade
- aio_launcher.c, liste de noms, non lu
- RobRunAIO.ini, cle masquerade

## Comment ca marche
FAIT a€” Avec masquerade a 1, le lanceur se copie dans %TEMP% sous un nom tire d une petite liste. BUILD.md section Masquerade.
FAIT a€” Liste : dllhost, taskhostw, RuntimeBroker, SearchProtocolHost, backgroundTaskHost, WmiPrvSE, smartscreen, ctfmon, sihost. Meme section.
FAIT a€” La copie est lancee avec --masq --ini <ini d origine> --payload <dossier>, puis le lanceur sort. Meme section.
FAIT a€” Le titre de fenetre suit le nom choisi et la fenetre de l overlay est une fenetre outil, donc ni l un ni l autre n apparait dans la liste des applications. Meme section.
FAIT a€” %TEMP% reste visible comme chemin dans le gestionnaire de taches, pas le nom ni le dossier. Meme section.
FAIT a€” masquerade vaut 1 par defaut. Meme section, tableau des reglages.
DECISION 2026-11-23 a€” Le masquage remplace le deliage de liste noyau, qui bugcheck. Meme section.

## Donnees lues ou ecrites
Ecrit : copie dans %TEMP%, masq.txt, masq_overlay.txt.

## Reglages
masquerade, 1 par defaut.

## Dependances
Droits d ecriture dans %TEMP%, liste de noms.

## Points de rupture
Un overlay de session precedente encore vivant fait echouer la copie en 0x20. _scratch/HANDOFF_aim_suivant.txt Â§5.
Le controle se fait par taille et hachage, jamais par nom, le nom variant. Meme section.

## Inconnus
Methode de tirage du nom. Gestion des collisions de nom.

## Sources
BUILD.md section Masquerade et tableau des reglages. _scratch/HANDOFF_aim_suivant.txt Â§5.

## Ancres de ligne
- aio_launcher.c:545, chemin de masq.txt, cite par sonde
- aio_launcher.c:1243, chemin de masq_overlay.txt, cite par sonde
- BUILD.md, section Masquerade, sans numero de ligne
