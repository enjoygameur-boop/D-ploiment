# Roles et couleurs de marqueur

## But
Distinguer policiers, braqueurs, civils et membres de clan par couleur et etiquette.
## Ou ca vit
- rr_draw.c:30-35, role_color, cite par sonde
- rr_draw.c:39-44, player_color, cite par sonde
- rr_game.c:5347, 5380-5381, detection, citee par sonde
- menu.html:576-577, legende

## Comment ca marche
FAIT a€” role_color compare la chaine : cop bleu, robber rouge, hubber ou civilian gris, citizen vert. rr_draw.c:32-35.
FAIT a€” player_color priorise clan violet, police cyan, puis mort, puis role. rr_draw.c:41-43.
FAIT a€” Si le local est cop, les autres cops recoivent RR_REL_POLICE. rr_game.c:5347, 5380-5381.
FAIT a€” RR_REL_CLAN et RR_REL_POLICE valent 1 et 2. rr_game.h:31.
FAIT a€” Un role inconnu retombe sur la palette zero. rr_draw.c:44.

## Donnees lues ou ecrites
Lit : role, relationships. Ecrit : pixels.

## Reglages
show_clan, show_police, aa_target_clan, aa_target_police. menu_bridge.h:28, 45.

## Dependances
rr_draw.c, rr_game.c, menu_bridge.h, menu.html.

## Points de rupture
Un role renomme fait perdre couleur et etiquette, sans erreur.
La detection des collegues depend du role du local. rr_game.c:5347.
Un joueur a deux drapeaux passe par rr_relationship_allowed. rr_game.h:41-43.

## Inconnus
Liste des roles possibles. Origine du champ role.

## Sources
rr_draw.c:30-44, 596-604. rr_game.c:5347, 5380-5381. rr_game.h:31, 41-43. menu.html:576-577.
