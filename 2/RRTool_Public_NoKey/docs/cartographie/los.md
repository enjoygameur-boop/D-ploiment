# Ligne de vue

## But
Savoir si un point de visee est masque, avec trois etats dont un inconnu.
## Ou ca vit
- 2_src_port/rr_los.c, rr_los_capture.c, rr_los_geom.c, rr_los_runtime.c et en-tetes
- README section Memory and validation lessons

## Comment ca marche
FAIT a€” Trois resultats : CLEAR, BLOCKED, UNKNOWN. README section Memory and validation lessons.
FAIT a€” Une geometrie perimee, non supportee ou incoherente reste inconnue. Meme section.
FAIT a€” Le modele est donne en exemple de systeme ou l absence de preuve ne devient pas un resultat positif. Meme section.
FAIT a€” aa_los_on et aa_clear_path sont passes a rr_aim_pick, la reprise de joint n a lieu que si le chemin est bloque. Corps de rr_aim_pick.
FAIT a€” Une ligne de vue qui reste inconnue se diagnostique par fraicheur de capture, identite de monde et formes supportees. README section Interpreting failures.

## Donnees lues ou ecrites
Lit : geometrie capturee. Ecrit : etat a trois valeurs.

## Reglages
aa_los_on.

## Dependances
rr_los.c, rr_los_capture.c, rr_los_geom.c, rr_los_runtime.c, rr_aim.c.

## Points de rupture
Geometrie perimee, tout reste inconnu, aucune reprise.
Patch du jeu sur les formes de collision, capture muette.

## Inconnus
Formes supportees. Frequence de capture. Effet du mode inconnu sur la visee.

## Sources
README sections Memory and validation lessons, Interpreting failures. Corps de rr_aim_pick.

## Ancres de ligne
- rr_aim.c:27, chaine de rejet parcourue avant la reprise de joint, citee par sonde
- _scratch/_probe_site.txt, appel de aa_clear_path, sans numero de ligne
