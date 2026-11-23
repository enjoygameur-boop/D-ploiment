# Mode dump

## But
Extraire des informations de la cible par un mode dedie.
## Ou ca vit
- 2_src_port/rr_esp.c, branche de dispatch, non lue
- 2_src_port/rr_esp.c.avant_dump_mode, 118774 octets
- 2_src_port/rr_classscan.c, 29453 octets

## Comment ca marche
FAIT a€” Le mode existe : une copie de rr_esp.c est nommee avant_dump_mode. Arbre Git.
FAIT a€” Les modes de diagnostic ont des exigences et effets differents, leur branche est a lire avant usage. BUILD.md section Check the overlay offline.
FAIT a€” Le nom du binaire de sauvegarde prouve une modification posterieure liee a ce mode. Deduit du nom de fichier.
INCONNU a€” nom du drapeau, sortie produite, conditions.

## Donnees lues ou ecrites
Ecrit : sortie de dump, nom INCONNU.

## Reglages
Aucun connu.

## Dependances
rr_esp.c, rr_classscan.c.

## Points de rupture
Non documente, toute regression est muette.
Ecritures eventuelles dans la cible non decrites.

## Inconnus
Tout le mode.

## Sources
BUILD.md section Check the overlay offline. Arbre Git, tailles des fichiers.

## Ancres de ligne
- _scratch/_chk2.txt:1, ligne de status publiee par le dispatch, citee par sonde
- 2_src_port/rr_esp.c.avant_dump_mode, copie anterieure du fichier, sans numero de ligne
