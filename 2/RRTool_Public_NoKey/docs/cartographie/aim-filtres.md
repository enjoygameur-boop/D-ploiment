# Filtres de cible

## But
Ecarter de la visee ce qui ne doit pas etre vise : local, vehicules, butin, caches, morts, au sol, civils, groupes non autorises.
## Ou ca vit
- rr_aim.c:27, chaine de rejet, citee par sonde
- rr_aim.c:28, relation, citee par sonde
- rr_game.c:5375-5376, calcul conditionne, cite par sonde
- rr_game.c:1598, civil, cite par sonde

## Comment ca marche
FAIT a€” La chaine rejette adresse nulle, invalide, mort, au sol, civil, vehicule, butin, local, cache. rr_aim.c:27.
FAIT a€” rr_relationship_allowed filtre clan et police. rr_aim.c:28.
FAIT a€” Le calcul de civil et de au sol est conditionne par aa_ignore_civil et aa_ignore_knocked. rr_game.c:5375-5376.
FAIT a€” citizen et civilian sont civils, la comparaison est exacte. rr_game.c:1598.
DECISION 2026-11-22 a€” rr_relationship_allowed passe en inclusion : un joueur a deux drapeaux passe si un interrupteur est actif. JOURNAL entree 2026-11-22.
DECISION 2026-11-22 a€” Le au sol repose sur la geometrie tete moins pieds sous 0.95 m, occupants de vehicule exemptes, la phase ne sert que de repli. Meme entree.
DECISION 2026-11-22 a€” aa_target_police par defaut a 1. Meme entree.

## Donnees lues ou ecrites
Lit : champs de joueur, configuration. Ecrit : decision de rejet.

## Reglages
aa_ignore_civil 0, aa_ignore_knocked 0, aa_target_clan, aa_target_police 1. menu_bridge.h:45, 48-49.

## Dependances
rr_aim.c, rr_game.c, rr_game.h:41-43.

## Points de rupture
Seuil de 0.95 m a confirmer, exemption vehicule a confirmer. JOURNAL entree 2026-11-22, ouvert.
Un role civil renomme, filtre inoperant.
p->dead n est jamais assigne dans le chemin reel, le filtre de cadavres n existe pas. _scratch/HANDOFF_aim_suivant.txt Â§6.

## Inconnus
Le seuil tient-il sur plusieurs sessions. Emplacement du calcul de mort.

## Sources
rr_aim.c:27-28. rr_game.c:1598, 5375-5376. rr_game.h:41-43, 72. JOURNAL entree 2026-11-22. _scratch/HANDOFF_aim_suivant.txt Â§6.
