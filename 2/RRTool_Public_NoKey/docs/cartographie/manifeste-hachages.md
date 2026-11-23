# Manifeste de hachages

## But
Relever taille et SHA-256 des quatre binaires du payload pour comparer une copie a sa source.

## Ou ca vit
_wl.txt:1-4.

## Comment ca marche
FAIT a€” Quatre lignes, format nom, taille, hash. _wl.txt:1-4.
FAIT a€” kd2.exe 222720, kernel-mode.sys 19968, RobRunPort.exe 2546176, WebView2Loader.dll 165440. _wl.txt:1-4.
FAIT a€” Mis a jour apres chaque build. JOURNAL entrees A3 termine et D01 attenue.
FAIT a€” Reste a la racine alors que les autres brouillons sont partis dans _scratch. JOURNAL entree Rangement de la racine.
FAIT a€” 1_run/RobRunPort.exe ignore par Git, seul le hachage garde la trace. .gitignore:3.
## Contradiction
_wl.txt:3 porte RobRunPort.exe 2546176 5EEE66029A0F21E7. Le JOURNAL cite 2546176 00E825936572F743 a l entree D01 attenue et 2545664 498800FF0C6B27A2 a l entree A3 termine. Trois etats pour une taille, sans date dans le fichier.
_wl.txt ne contient pas RobRunAIO.exe alors que le journal releve des hachages d AIO.

## Donnees lues ou ecrites
Ecrit : quatre lignes. Aucune lecture par le produit.

## Reglages
Aucun.

## Dependances
Outil de hachage, hors depot.

## Points de rupture
Sans date par ligne, un hachage ne dit pas a quelle build il correspond.
Aucun script du depot ne compare ce fichier.

## Inconnus
Producteur du fichier : aucun script de generation present.

## Sources
_wl.txt:1-4. .gitignore:3. JOURNAL_AGENT.txt entrees A3 termine, D01 attenue, Rangement de la racine.
