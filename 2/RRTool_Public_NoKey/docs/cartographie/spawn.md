# Creation de processus et helper

## But
Creer un processus cible, garder la propriete des handles et charger un helper optionnel.
## Ou ca vit
- 2_src_port/rr_spawn.c, 21105 octets, non lu
- 2_src_port/rr_spawn.h, 2561 octets, non lu

## Comment ca marche
FAIT a€” Le module est decrit comme creation de processus, propriete des handles et chargement optionnel d un helper. README carte des sources.
INCONNU a€” processus vises, conditions de chargement, duree de vie.

## Donnees lues ou ecrites
Lit : chemin d executable. Ecrit : processus, handles.

## Reglages
Aucun connu.

## Dependances
rr_spawn.c, rr_spawn.h, API de creation de processus.

## Points de rupture
Un chemin d executable change, creation muette.
Handle non ferme, fuite.

## Inconnus
Tout le corps du module.

## Sources
README carte des sources. Arbre Git, tailles des fichiers.

## Ancres de ligne
- _scratch/_f2.txt:1, liste de processus relevee, citee par sonde
- rr_spawn.h, sans numero de ligne
- README.md, carte des sources, sans numero de ligne
