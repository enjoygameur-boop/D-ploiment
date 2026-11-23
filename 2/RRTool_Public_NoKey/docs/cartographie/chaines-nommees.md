# Chaines d adresses nommees

## But
Surcharger par fichier des adresses exprimees sous forme de chaines nommees, sans recompiler.

## Ou ca vit
- 2_src_port/rr_chain.h, rr_chain.c, non lus
- rr_chain.h:1, commentaire d en-tete, cite par sonde
- rr_chain.h:24, fonction de chargement, cite par sonde
- rr_esp.c:1223, rr_game.c:5002, appels, cites par sonde
- rr_esp.c:1154, fichier de selftest, cite par sonde

## Comment ca marche
FAIT a€” rr_chain.h se presente comme expressions d adresses nommees chargees depuis robrun_chain.txt. rr_chain.h:1.
FAIT a€” Une fonction de chargement prend un chemin et rend le nombre de symboles. rr_chain.h:24.
FAIT a€” robrun_chain.txt est charge au demarrage. rr_esp.c:1223, rr_game.c:5002.
FAIT a€” Le selftest emploie un fichier dedie, selftest_chain.txt. rr_esp.c:1154.
FAIT a€” Le selftest verifie deux cas : fichier a deux symboles analyse, symboles enregistres. selftest.log:22-23.
FAIT a€” Le module est decrit comme analyse et evaluation d expressions optionnelles. README.md carte des sources.
FAIT a€” robrun_chain.txt est ignore par Git et suit le sort du cache runtime. .gitignore:8, aio_launcher.c:1265-1266.
## Donnees lues ou ecrites
Lit : robrun_chain.txt, selftest_chain.txt. Ecrit : table de symboles en memoire.

## Reglages
Aucun reglage d execution. Le fichier est optionnel.

## Dependances
rr_chain.c, rr_mem.c.

## Points de rupture
Un fichier mal forme casse le demarrage ou laisse les symboles absents.
Les chaines portent des offsets figes, un patch du jeu les perime sans erreur visible.
Le fichier vit dans le dossier de travail, donc en %TEMP% en mode masque.

## Inconnus
Syntaxe des expressions. Evaluation reelle. Origine du fichier, ecrit a la main ou genere.

## Sources
rr_chain.h:1, 24, rr_esp.c:1154, 1223, rr_game.c:5002, aio_launcher.c:1265-1266, cites par sonde. selftest.log:22-23. README.md carte des sources. .gitignore:8.
