# Mapper noyau

## But
Charger l image du pilote sans cycle de dechargement normal.

## Ou ca vit
- 4_src_mapper/kd2_src/, solution et sources, non lues
- 1_run/kd2.exe, binaire, hors perimetre sauf hachage
- BUILD.md section Build the mapper

## Comment ca marche
FAIT a€” MSBuild sur kdmapper.sln, Release x64, place kdmapper.exe dans 4_src_mapper/kd2_src/build. BUILD.md section Build the mapper.
FAIT a€” Le paquet d execution renomme cet artefact en kd2.exe. Meme section.
FAIT a€” La solution garde des blocs de canal anciens et des dependances amont, non requis pour le transport de l overlay. Meme section.
FAIT a€” Construire est distinct de mapper. Meme section.
FAIT a€” L AIO mappe le pilote par kd2.exe --auto. BUILD.md section all-in-one launcher.
FAIT a€” L image mappee est residente sans cycle de dechargement, une fermeture de l overlay ou un rebuild ne la remplace pas. BUILD.md section Build the driver.
FAIT a€” Une image au hachage rejete du 2026-11-07 n est jamais mappee. BUILD.md section all-in-one launcher.

## Donnees lues ou ecrites
Lit : kernel-mode.sys. Ecrit : image noyau residente.

## Reglages
Aucun reglage connu hors --auto.

## Dependances
MSBuild, jeu d outils v143, SDK Windows.

## Points de rupture
Un pilote deja mappe n est pas remplace : un nouveau .sys exige un redemarrage. BUILD.md section Build the driver.
Deux drivers charges se genent. _scratch/MAINTENANCE_fast_scan.txt section E6.
Le refus de mappage sous VBS, Hyper-V ou integrite memoire est traite par le lanceur. BUILD.md section all-in-one launcher.

## Inconnus
Contenu des sources kd2. Version amont retenue.

## Sources
BUILD.md sections Build the mapper, all-in-one launcher, Build the driver. _scratch/MAINTENANCE_fast_scan.txt E6.
## Ancres de ligne
- _wl.txt:1, hachage de kd2.exe, artefact du mapper
- _scratch/SINGLE_BUILD.md:1, banniere d obsolescence citant le mapper integre
- BUILD.md, section Build the mapper, sans numero de ligne
