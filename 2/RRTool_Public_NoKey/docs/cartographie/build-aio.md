# Build de l executable tout-en-un

## But
Produire RobRunAIO.exe, qui embarque pilote, overlay et loader WebView2 et pilote leur ordre de demarrage.

## Ou ca vit
- 2_src_port/build_aio.bat, non lu, cite par _scratch/_aio.txt:1
- 2_src_port/aio_launcher.c, non lu
- BUILD.md section Build the all-in-one launcher

## Comment ca marche
FAIT a€” Embarque les binaires courants de 1_run : kd2.exe, kernel-mode.sys, RobRunPort.exe, WebView2Loader.dll. BUILD.md section all-in-one launcher.
FAIT a€” Les binaires doivent etre reconstruits avant. Meme section.
FAIT a€” Sortie 2_src_port/RobRunAIO.exe recopiee vers 1_run/RobRunAIO.exe. Meme section.
FAIT a€” Refus de demarrer sous VBS, Hyper-V ou integrite memoire. Meme section.
FAIT a€” Le manifeste demande l elevation. Meme section.
FAIT a€” Commande reelle : cmd /c build_aio.bat depuis 2_src_port. _scratch/_aio.txt:1.
FAIT a€” Une execution a rendu EXIT=0. _scratch/_aio.txt:3-5.
FAIT a€” 2_src_port/RobRunAIO.exe sorti du suivi Git. .gitignore:12.
## Contradiction
_scratch/_aio.txt:6 note AIO_MATCH=False, alors que l entree de journal correspondante conclut a une livraison valide. La sonde precede le protocole de double hachage de _scratch/HANDOFF_suivant.txt Â§10.

## Donnees lues ou ecrites
Lit : les quatre binaires de 1_run. Ecrit : 2_src_port/RobRunAIO.exe, 1_run/RobRunAIO.exe.

## Reglages
Aucun a la compilation. Reglages d execution dans RobRunAIO.ini, voir aio-supervision.md.

## Dependances
build_port.bat doit avoir tourne avant. Pilote et overlay doivent etre coherents. BUILD.md section Runtime artifact map.

## Points de rupture
Un overlay perime dans 1_run est embarque tel quel, le binaire ne reflete pas les sources.
Modification non committee du .bat invisible.
Hachage du pilote controle au demarrage, un pilote reconstruit le change. BUILD.md section Masquerade.

## Inconnus
Contenu de build_aio.bat. Liste et numeros des ressources embarquees.

## Sources
BUILD.md section all-in-one launcher. _scratch/_aio.txt:1-7. .gitignore:12. JOURNAL entrees aio embleme, licence.
