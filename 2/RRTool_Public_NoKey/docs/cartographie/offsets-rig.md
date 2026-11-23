# Provenance de rig

## But
Conserver la provenance de la palette et des os ponderes ou optionnels.
## Ou ca vit
- offsets/robrun_rig.json, 132931 octets
- 2_src_port/rr_cham_model.h, rr_rig_map.h

## Comment ca marche
FAIT a€” Le JSON conserve la provenance palette et os ponderes ou optionnels. BUILD.md section Understand the offset inputs.
FAIT a€” Les en-tetes de rig ont ete exportes hors ligne par un outil absent. Meme section.
FAIT a€” Ne pas reordonner les indices de palette a la main pour corriger un probleme de runtime. Meme section.
FAIT a€” Les noms de champs, hashes, noms d os et indices de palette sont des donnees a garder alignees sur leurs entrees. README section Source map.

## Donnees lues ou ecrites
Aucune a l execution. Source de generation des en-tetes.

## Reglages
Aucun.

## Dependances
Exportateur absent, rr_cham_model.h, rr_rig_map.h.

## Points de rupture
Un reexport different des indices casse l appariement des os.
Un patch du jeu changeant les noms d os rend la table muette.

## Inconnus
Format du JSON. Outil d export.

## Sources
BUILD.md section Understand the offset inputs. README section Source map.

## Ancres de ligne
- selftest.log:12, offset de transformation lu depuis le dump
- offsets/robrun_rig.json, provenance de palette, sans numero de ligne
- BUILD.md, section Understand the offset inputs, sans numero de ligne
