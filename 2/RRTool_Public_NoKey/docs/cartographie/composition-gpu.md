# Composition de la surface

## But
Presenter une surface transparente par dessus le jeu.

## Ou ca vit
- 2_src_port/gpu.cpp, gpu.h, non lus
- README.md section How one frame works

## Comment ca marche
FAIT a€” Direct2D et DirectWrite servent aux formes 2D et au texte. README.md section How one frame works.
FAIT a€” Les meshes de personnage sont rasterises sur CPU puis envoyes en textures. Meme section.
FAIT a€” D3D11 et DirectComposition presentent la surface transparente. Meme section.
FAIT a€” La presentation peut etre sautee quand la signature de frame n a pas change ou que la file du compositeur est pleine. Meme section.
FAIT a€” gpu.cpp est un hote C++ a cote des sources C. BUILD.md:38-39.
INCONNU a€” taille des textures, format de la signature de frame, seuil de file.

## Donnees lues ou ecrites
Lit : instantane, signature de frame. Ecrit : surface compositee.

## Reglages
Aucun reglage connu.

## Dependances
gpu.cpp, gpu.h, D3D11, DirectComposition, Direct2D.

## Points de rupture
Un pilote graphique ou une session distante peut refuser la composition.
La signature de frame sautee fige l affichage si un champ n est pas melange dans le MIX. _scratch/HANDOFF_aim_suivant.txt Â§2.

## Inconnus
Tout le corps de gpu.cpp. Voir MANQUES.md.

## Sources
README.md section How one frame works. BUILD.md:38-39. _scratch/HANDOFF_aim_suivant.txt Â§2.