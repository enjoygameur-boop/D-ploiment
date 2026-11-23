# Asservissement de la souris

## But
Convertir l ecart ecran en mouvement de souris lisse, sans depassement.
## Ou ca vit
- 2_src_port/rr_aim.c, rr_aim_step, cite par sonde dans _scratch/_probe_site.txt
- _scratch/HANDOFF_suivant.txt Â§6 et Â§15

## Comment ca marche
FAIT a€” rr_aim_step recoit l ecart, le fov, la hauteur, aa_smooth, aa_aim_cal, elapsed, l etat du bouton gauche et aa_stick. _scratch/_probe_site.txt.
FAIT a€” Asservissement PI avec terme integral borne, anti-windup et repli au changement de signe. _scratch/HANDOFF_suivant.txt Â§6.
FAIT a€” aa_stick plafonne l assouplissement du gain. Meme section.
FAIT a€” aa_aim_cal vaut 100 fois les counts par pixel de reference en 1080p et 60 degres verticaux, et depend de la sensibilite du jeu. README section Controls and settings.
FAIT a€” Le mouvement n est applique que s il est non nul. _scratch/_probe_site.txt.

## Donnees lues ou ecrites
Lit : ecart, temps ecoule, etat du bouton. Ecrit : deplacement souris.

## Reglages
aa_smooth, aa_aim_cal, aa_stick, defaut 50. _scratch/HANDOFF_suivant.txt Â§15.

## Dependances
rr_aim.c, envoi de mouvement souris.

## Points de rupture
Sensibilite du jeu changee, calibration fausse, visee qui depasse ou traine.
aa_stick trop haut, oscillation. Trop bas, trainee. _scratch/HANDOFF_suivant.txt Â§15.

## Inconnus
Forme exacte des gains. Comportement au changement de signe en pratique.

## Sources
_scratch/_probe_site.txt. _scratch/HANDOFF_suivant.txt Â§6, Â§15. README section Controls and settings.

## Ancres de ligne
- rr_esp.c:433, journal de l etat de visee, cite par sonde
- rr_esp.c:490, journal du mouvement applique, cite par sonde
- rr_esp.c:818, appel de aa_tick, cite par sonde
