# Cache d indices de decouverte

## But
Conserver d une session a l autre des indices de decouverte pour accelerer l attachement.

## Ou ca vit
- rr_game.c:58, define RUNTIME_FILE, cite par sonde
- rr_game.c:448, construction du chemin, cite par sonde
- aio_launcher.c:1206-1213, deplacement et suppression, cite par sonde
- .gitignore:7, fichier ignore

## Comment ca marche
FAIT a€” Le nom du fichier est une constante RUNTIME_FILE valant robrun_runtime.txt. rr_game.c:58.
FAIT a€” Le chemin est construit a cote de l overlay. rr_game.c:448.
FAIT a€” Le lanceur le met de cote pour forcer un balayage propre lors d un reattachement. aio_launcher.c:1206-1211, BUILD.md section Menu wait and reattach.
FAIT a€” Il peut aussi le supprimer. aio_launcher.c:1213.
FAIT a€” Le cache ne transforme pas une vieille adresse de tas en adresse valide dans un nouveau processus. README.md section Controls and settings.
FAIT a€” Le fichier est ignore par Git. .gitignore:7.FAIT a€” Il vit dans le dossier de travail, donc en %TEMP% en mode masque. rr_game.c:438, cite par sonde.
FAIT a€” robrun_chain.txt suit le meme sort que le cache runtime. aio_launcher.c:1265-1266, cite par sonde.

## Donnees lues ou ecrites
Ecrit puis relit : robrun_runtime.txt, robrun_chain.txt.

## Reglages
Aucun reglage d execution.

## Dependances
rr_game.c, aio_launcher.c, rr_chain.c.

## Points de rupture
Un cache perime oriente la decouverte vers des adresses mortes, d ou la mise de cote au reattachement.
En mode masque, il s ecrit dans %TEMP%, donc un nettoyage de %TEMP% le perd. rr_game.c:438.

## Inconnus
Format du fichier. Ce qu il contient exactement.

## Sources
rr_game.c:58, 438, 448, cites par sonde. aio_launcher.c:1206-1213, 1265-1266, cites par sonde. BUILD.md section Menu wait and reattach. README.md section Controls and settings. .gitignore:7.
