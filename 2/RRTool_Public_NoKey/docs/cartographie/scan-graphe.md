# Recherche dans le graphe et en memoire

## But
Retrouver des objets sans offset connu, par parcours borne du graphe managed et balayage memoire.

## Ou ca vit
- 2_src_port/rr_classscan.c, rr_nodescan.c, rr_find.c, rr_find.h, non lus
- README.md carte des sources

## Comment ca marche
FAIT a€” Trois modules distincts : recherche de classe, de noeud et de motif. README.md carte des sources.
FAIT a€” Les trois sont decrits comme recherches bornees de graphe et de memoire. Meme section.INCONNU a€” bornes reelles, points d entree, cout par passe.

## Donnees lues ou ecrites
Lit : memoire du jeu. Ecrit : resultats de recherche, sans persistance connue.

## Reglages
Aucun reglage connu.

## Dependances
rr_unity.c pour la lecture d objets et de chaines.

## Points de rupture
Un balayage non borne bloque le worker. Le decoupage en passes de 3 s de BUILD.md:52-55 ne couvre que le repli de game_init, pas ces modules.
Patch du jeu, noms de classe changes, recherche muette.

## Inconnus
Contenu des trois modules. Voir MANQUES.md.

## Sources
README.md carte des sources. Arbre Git, tailles des fichiers.
