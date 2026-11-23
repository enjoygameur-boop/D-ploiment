# Projection monde vers ecran

## But
Convertir un point du monde en pixels, en passant par l espace camera.

## Ou ca vit
- 2_src_port/rr_draw.c, game_w2s, non lu
- 2_src_port/gpu.cpp, non lu
- selftest.log:16-21, cas de reference
- README.md ordre de lecture point 5

## Comment ca marche
FAIT a€” game_w2s est appele depuis rr_draw.c vers gpu.cpp. README.md ordre de lecture point 5.
FAIT a€” Le selftest couvre cinq cas : point sur l axe projete au centre, rayon a 45 degres a droite place par le rapport d aspect, rayon sur le bord horizontal, rayon a 45 degres vers le haut, point derriere la camera rejete. selftest.log:17-21.
FAIT a€” Un point derriere la camera est rejete, pas projete a l envers. selftest.log:21.
FAIT a€” Le fov de camera sert de reference angulaire dans les calculs de visee. Corps de rr_aim_pick.
FAIT a€” La distance en profondeur reduit l occupation en pixels d un meme mouvement monde. README.md exercice 2.

## Donnees lues ou ecrites
Lit : position camera, fov, dimensions client. Ecrit : coordonnees ecran.

## Reglages
Aucun reglage direct. Les dimensions viennent du rectangle client. _scratch/_probe_site.txt.

## Dependances
rr_draw.c, gpu.cpp, camera du releve.
## Points de rupture
Une camera lue trop tot ou trop tard decale les marqueurs. README.md section How one frame works, echantillonnage camera separe.
Un changement de fov ou de resolution deplace la correspondance angulaire.
Un patch du jeu changeant la disposition camera casse la projection sans erreur franche.

## Inconnus
Corps de game_w2s et de la matrice de vue. Convention d axe et signe.
Le cas de reference a 45 degres ne dit pas si l axe vertical est inverse.

## Sources
selftest.log:16-21. README.md ordre de lecture point 5, section How one frame works, exercice 2. Corps de rr_aim_pick dans _scratch/_probe_police.txt. _scratch/_probe_site.txt.
