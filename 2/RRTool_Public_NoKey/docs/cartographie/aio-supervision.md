# Supervision et journaux du lanceur

## But
Suivre l etat de l overlay et tracer le demarrage.
## Ou ca vit
- aio_launcher.c:94, commentaire sur les fichiers ecrits, cite par sonde
- aio_launcher.c:545, 1206-1213, 1243, 1262-1266, cites par sonde

## Comment ca marche
FAIT a€” L overlay ecrit status.log, robrun_runtime.txt et CoreRR.cfg. aio_launcher.c:94.
FAIT a€” Le lanceur trace le deplacement et la suppression du cache par log_add. aio_launcher.c:1211-1213.
FAIT a€” Le journal du lanceur est aio.log, il ne contient que le demarrage, pas le journal de decouverte. _scratch/HANDOFF_aim_suivant.txt Â§5.
FAIT a€” Le journal du port s ecrit dans discovery.log, dans le repertoire courant de l overlay, donc %TEMP%, ou a defaut dans 1_run\payload. Meme section.
FAIT a€” L AIO se ferme apres extraction et l overlay se masque, donc Get-Process ne les voit pas ; seul le processus du jeu et l affichage font foi. JOURNAL entree Test en jeu.
FAIT a€” masq.txt suit le lanceur, masq_overlay.txt le dossier payload. aio_launcher.c:545, 1243.

## Donnees lues ou ecrites
Ecrit : aio.log, status.log, discovery.log, masq.txt, masq_overlay.txt.

## Reglages
hide_launcher, masquerade.

## Dependances
aio_launcher.c, rr_game.c pour dlog.

## Points de rupture
Le journal du port n est pas dans le dossier du lanceur, une recherche au mauvais endroit conclut a tort.
Un overlay vivant empeche la copie, le lancement rejoue l ancien port. _scratch/HANDOFF_aim_suivant.txt Â§5.

## Inconnus
Contenu de aio.log. Conditions d ecriture de status.log.

## Sources
aio_launcher.c:94, 545, 1206-1213, 1243, 1262-1266, cites par sonde. _scratch/HANDOFF_aim_suivant.txt Â§5. JOURNAL entree Test en jeu.
