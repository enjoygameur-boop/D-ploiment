# Chams et squelettes

## But
Afficher une silhouette ou un squelette a travers les murs.
## Ou ca vit
- 2_src_port/rr_cham_model.h, 535879 octets
- rr_vehicle_cham_model.h, 64599 octets
- rr_cham_types.h, rr_body_joints.h, rr_rig_map.h
- offsets/robrun_rig.json, 132931 octets

## Comment ca marche
FAIT a€” Palette de 94 emplacements, mesh de reference a 86 os ponderes, 8 optionnels. README section Rig and pose lessons.
FAIT a€” L affichage anatomique exclut arme, chargeur et trois aides de sac, laissant jusqu a 89 articulations et 88 liens. Meme section.
FAIT a€” Un joint optionnel manquant supprime les liens concernes. Meme section.
FAIT a€” Les joints natifs sont apparies par nom et ascendance, puis filtres sur le mouvement relatif a la racine. Meme section.
FAIT a€” Le mesh de reference peut differer du vetement ou de l equipement reel. Meme section.
FAIT a€” Les chams butin et vehicule sont des reglages persistes et testes. selftest.log:3.
FAIT a€” L exportateur d origine est absent, la provenance reste dans le JSON et les en-tetes. Meme section.

## Donnees lues ou ecrites
Lit : transformations de joints, tables de rig. Ecrit : pixels rasterises, textures.

## Reglages
Interrupteurs de chams et palette. menu_bridge.h.

## Dependances
rr_cham_model.h, rr_rig_map.h, rr_body_joints.h, rr_pose_gate.h, gpu.cpp.

## Points de rupture
Un rig modifie par le jeu casse l appariement des noms.
Palette reordonnee a la main, indices faux. BUILD.md section Offset inputs.

## Inconnus
Corps de la rasterisation et du filtrage. Cout par personnage.

## Sources
README section Rig and pose lessons. selftest.log:3. BUILD.md section Offset inputs.
