# Radar et marqueurs de monde

## But
Afficher une vue radar et un ensemble borne de marqueurs proches.
## Ou ca vit
- 2_src_port/rr_world_marker_select.h, 857 octets, non lu
- rr_draw.c:346, 464, 488, filtres de relation, cites par sonde
- selftest.log:2, aller-retour radar

## Comment ca marche
FAIT a€” rr_world_marker_select.h garde un ensemble borne de marqueurs proches. README carte des sources.
FAIT a€” Le radar est un reglage persiste et teste en aller-retour. selftest.log:2.
FAIT a€” Les marqueurs de joueurs passent par rr_relationship_allowed. rr_draw.c:346, 464, 488.
FAIT a€” Les vehicules sont exclus du filtre de relation, le test porte sur is_vehicle. rr_draw.c:346.
INCONNU a€” rayon, capacite, ordre de selection, rendu.

## Donnees lues ou ecrites
Lit : positions du releve. Ecrit : pixels de radar et de marqueur.

## Reglages
Reglages radar du bloc de configuration. noms exacts INCONNU.

## Dependances
rr_world_marker_select.h, rr_draw.c, rr_game.c.

## Points de rupture
Capacite depassee, marqueurs perdus silencieusement.
Patch du jeu, positions fausses, radar vide.

## Inconnus
Tout le corps du selecteur et du rendu radar.

## Sources
README carte des sources. rr_draw.c:346, 464, 488. selftest.log:2.
