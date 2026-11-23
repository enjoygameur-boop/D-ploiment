# Prediction de cible

## But
Avancer le point de visee pour compenser le vol de la cible.
## Ou ca vit
- 2_src_port/rr_aim.c, rr_aim_motion_point, cite par sonde dans _scratch/_probe_site.txt
- _scratch/HANDOFF_suivant.txt Â§6 et Â§7

## Comment ca marche
FAIT a€” La prediction emploie snapshot_at, last_position_at et l instant courant. _scratch/_probe_site.txt.
FAIT a€” Le lead est porte a 45 m/s, avec plancher d echantillonnage, axe y jamais touche. _scratch/HANDOFF_suivant.txt Â§6.
FAIT a€” La prediction est desactivee en vehicule. _scratch/_probe_site.txt.
FAIT a€” La replication tourne a 20 Hz : sous 100 ms d echantillonnage on mesure du jitter, pas une vitesse. _scratch/HANDOFF_suivant.txt Â§7.
FAIT a€” Helios, vecteur trop instable, plafonne a 25 m/s. Meme section.
FAIT a€” La detection aerienne repose sur vz et n est pas validee en jeu. Meme section.

## Donnees lues ou ecrites
Lit : positions successives, horodatages. Ecrit : point predit.

## Reglages
Plafond 45 m/s, plancher d echantillonnage, plafond helios 25 m/s.

## Dependances
rr_aim.c, game_w2s.

## Points de rupture
Changement de cadence de replication, lead trop court ou trop long.
Cible en vehicule, prediction coupee, point brut.

## Inconnus
Formule exacte. Validation en jeu de la detection aerienne.

## Sources
_scratch/_probe_site.txt. _scratch/HANDOFF_suivant.txt Â§6, Â§7.

## Ancres de ligne
- rr_esp.c:433, journal de l etat de visee, cite par sonde
- rr_esp.c:490, journal du mouvement, cite par sonde
- _scratch/_probe_site.txt, appel de rr_aim_motion_point, sans numero de ligne
