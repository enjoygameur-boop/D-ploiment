# Selection de cible

## But
Choisir la cible la plus proche du reticule dans un cone, avec verrou maintenu.
## Ou ca vit
- 2_src_port/rr_aim.c, rr_aim_pick, cite par sonde dans _scratch/_probe_police.txt
- rr_aim.h, 2066 octets

## Comment ca marche
FAIT a€” Le rayon vaut aa_fov_px, ou 150 si le reglage est nul. Corps de rr_aim_pick.
FAIT a€” La limite angulaire est derivee du rayon, du fov et de la hauteur, pour que l anneau ecran et la limite decrivent le meme angle. Meme corps.
FAIT a€” Le score vaut l angle plus 0.02 fois la distance. Meme corps.
FAIT a€” Un verrou tenu garde le pointeur jusqu a ce qu un rival le batte de aa_switch_margin. Meme corps.
FAIT a€” Le groupe de joints vient de aa_bone. Meme corps.
FAIT a€” Si le joint choisi est bloque, rr_aim_visible_point reprend la meme zone. Meme corps.
FAIT a€” Les cibles non finies, hors portee ou hors cone sont rejetees. Meme corps.

## Donnees lues ou ecrites
Lit : releve, camera, configuration. Ecrit : cible retenue, ecart ecran.

## Reglages
aa_fov_px, aa_switch_margin, aa_bone, aa_dist.

## Dependances
rr_aim.c, game_w2s, rr_aim_point, rr_aim_visible_point.

## Points de rupture
Changement de fov ou de resolution, cone decale.
Patch du jeu sur les joints, points de visee faux.

## Inconnus
Valeurs par defaut de aa_fov_px et aa_bone. Effet du groupe 7 a 9.

## Sources
Corps de rr_aim_pick dans _scratch/_probe_police.txt. rr_aim.h.

## Ancres de ligne
- rr_aim.c:27, chaine de rejet, citee par sonde
- rr_aim.c:28, filtre de relation, cite par sonde
- _scratch/_probe_police.txt, corps de rr_aim_pick, sans numero de ligne
