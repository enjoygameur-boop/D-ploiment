# Porte de pose

## But
Eviter d afficher une pose alternative breve en confirmant un changement de branche sur un intervalle borne.
## Ou ca vit
- 2_src_port/rr_pose_gate.h, 2838 octets, non lu
- 2_src_port/rr_cham_coherence.h, 1179 octets, non lu
- README section Rig and pose lessons

## Comment ca marche
FAIT a€” Un changement de branche brusque est confirme sur un intervalle borne. README section Rig and pose lessons.
FAIT a€” Le procede reduit les poses alternatives breves et ajoute un court delai au mouvement brusque. Meme section.
FAIT a€” Le lecteur construit les poses monde et les matrices de peau avant filtrage du petit mouvement relatif a la racine. Meme section.
INCONNU a€” duree de l intervalle, critere de retour a la pose acceptee.

## Donnees lues ou ecrites
Lit : poses successives. Ecrit : pose retenue.

## Reglages
Aucun reglage connu.

## Dependances
rr_pose_gate.h, rr_cham_coherence.h, rr_game.c.

## Points de rupture
Intervalle trop long, squelette en retard sur le mouvement reel.
Patch du jeu changeant les noms de branche, confirmation muette.

## Inconnus
Tout le corps des deux en-tetes. Cas ou la pose revient avant la fin de l intervalle.

## Sources
README section Rig and pose lessons. Tailles des fichiers, arbre Git.

## Ancres de ligne
- rr_esp.c:465, filtre de rendu sur l etat du joueur, cite par sonde
- rr_game.c:5375, calcul conditionne de l etat au sol, cite par sonde
- rr_pose_gate.h, sans numero de ligne
