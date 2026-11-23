# Veil, masquage par le noyau

## But
Faire disparaitre le processus du produit des listes systeme, par deliage de ActiveProcessLinks.

## Ou ca vit
- BUILD.md section Masquerade
- 3_src_driver/wm_drv.c, non lu
- 1_run/RobRunAIO.ini, cle hide_launcher

## Comment ca marche
FAIT a€” Le deliage provoque un bugcheck 0x109 sur cette build. BUILD.md section Masquerade.
FAIT a€” Cause : PatchGuard recoupe PsActiveProcessHead avec KiProcessListHead et PspCidTable. Meme section.
FAIT a€” Le pilote refuse les demandes de veil par defaut, SYSTEM\WmPort\Veil = 0. Meme section.FAIT a€” hide_launcher vaut 0 par defaut et s appuie sur ce deliage. BUILD.md tableau des reglages.
DECISION 2026-11-23 a€” Veil desactive par defaut, masquage par copie et renommage a la place.

## Donnees lues ou ecrites
Lit : valeur SYSTEM\WmPort\Veil. Ecrit : chaine de processus noyau si active.

## Reglages
SYSTEM\WmPort\Veil, 0 par defaut. hide_launcher, 0 par defaut.

## Dependances
wm_drv.c, RobRunAIO.ini.

## Points de rupture
Activer hide_launcher sur une build ou PatchGuard recoupe encore provoque un bugcheck 0x109.
Le deliage n est pas un cycle de vie complet, l entree reste auto-referencee. _scratch/_probe_rel.txt.

## Inconnus
Condition exacte de bascule cote pilote. Emplacement de l ecriture Veil.

## Sources
BUILD.md section Masquerade et tableau des reglages. _scratch/_probe_rel.txt.

## Ancres de ligne
- docs/RISQUES.md:14, parade R08 sur l integrite memoire et l hyperviseur
- _scratch/_probe_rel.txt, commentaire de overlay_exit sur le deliage, sans numero de ligne
- BUILD.md, section Masquerade, sans numero de ligne
