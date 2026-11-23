# Protocole noyau

## But
Definir la requete et la reponse entre le client et le pilote.

## Ou ca vit
- 3_src_driver/wm.h, definitions d IOCTL, non lu
- 3_src_driver/wm_drv.c, WmDispatch(), non lu
- BUILD.md section Build the driver

## Comment ca marche
FAIT a€” WM_PACKET, les definitions d IOCTL et WmDispatch() doivent s accorder avec rr_mem.c sur l emballage, le sens des champs, les plafonds et la disposition de reponse. BUILD.md section Build the driver.
FAIT a€” METHOD_BUFFERED reutilise le tampon systeme, le pilote copie les champs de requete avant de l ecraser. Meme section.
FAIT a€” Le pilote est construit avec /kernel et lie les bibliotheques WDK. BUILD.md:96.
FAIT a€” Le script imprime les commandes de deploiement sans les executer. BUILD.md:98-99.
INCONNU a€” numeros d IOCTL, disposition de WM_PACKET, plafonds cote noyau.

## Donnees lues ou ecrites
Lit : tampon systeme de la requete. Ecrit : tampon systeme de la reponse.

## Reglages
Aucun reglage d execution connu.

## Dependances
wm.h, wm_drv.c, rr_mem.c, WDK.

## Points de rupture
Toute retouche d un cote du contrat casse l autre sans erreur de compilation.
Un pilote reconstruit change le hachage controle par le lanceur. BUILD.md section Masquerade.
Une image mappee survit au rebuild, seul un redemarrage la retire. BUILD.md section Build the driver.

## Inconnus
Tout le contenu de wm.h et wm_drv.c. Voir MANQUES.md.

## Sources
BUILD.md:88-99 et section Build the driver.