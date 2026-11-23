# Decouverte du monde

## But
Trouver les modeles de monde, de roster et de camera, puis publier des releves exploitables.

## Ou ca vit
- README.md section How one frame works
- 2_src_port/rr_game.c, non lu, game_init, scan_worker, game_snapshot
- _scratch/_chk2.txt, sortie de status.log

## Comment ca marche
FAIT a€” Un worker de decouverte rafraichit les caches monde, roster et marqueurs. README.md section How one frame works.
FAIT a€” Le fil d echantillonnage recopie les entrees publiees sous verrou, lit transformations et rigs, et publie un instantane. Meme section.
FAIT a€” Le verrou protege la publication, pas le balayage entier. README.md, ordre de lecture point 4.
FAIT a€” Les recontroles d identite, bornes de capacite, retention de pose recente et reprises reduisent les incoherences sans rendre les ecritures atomiques. Meme section.
FAIT a€” game_init n emprunte que le chemin dictionnaire, le repli tas revient au worker par passes de 3 s a curseur tournant. BUILD.md:52-55.
FAIT a€” status.log publie un compte de personnages, l etat camera, un compte de hits et de candidats, un identifiant accepte et une periode de 50 ms. _scratch/_chk2.txt.FAIT a€” Un releve reel montre 5 a 7 personnages et des exceptions comptees. _scratch/_chk2.txt.
FAIT a€” La camera est marquee modele. _scratch/_chk2.txt.
FAIT a€” Aucun monde ni roster plausible, causes a inspecter : identite d attachement, scene courante, audit d offsets. README.md section Interpreting failures.

## Donnees lues ou ecrites
Lit : memoire du jeu. Ecrit : caches internes, status.log, robrun_runtime.txt.

## Reglages
Periode d echantillonnage 50 ms. Passe de repli 3 s.

## Dependances
rr_game.c, rr_mem.c, rr_unity.c, offsets.

## Points de rupture
Patch du jeu, offsets morts, roster vide. README.md section Interpreting failures, docs/RISQUES.md:7 (R01).
Une scene changee invalide les adresses de tas. README.md section Memory and validation lessons.

## Inconnus
Sequence d appels exacte de game_init, scan_worker et game_snapshot.
Signification du champ accepted de status.log.

## Sources
README.md sections How one frame works, Memory and validation lessons, Interpreting failures. BUILD.md:52-55. _scratch/_chk2.txt.
