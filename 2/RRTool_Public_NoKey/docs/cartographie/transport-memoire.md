# Transport memoire en mode utilisateur

## But
Lire et ecrire la memoire du jeu par lots bornes, via un IOCTL adresse au pilote.

## Ou ca vit
- README.md section Memory and validation lessons
- 2_src_port/rr_mem.c, rr_mem.h, non lus
- 3_src_driver/wm_drv.c, contrat cote noyau, non lu

## Comment ca marche
FAIT a€” Un IOCTL est envoye au pilote, qui recopie les octets demandes dans sa reponse tamponnee. README.md section How one frame works.
FAIT a€” rr_read limite une requete a 64 Kio. README.md section Memory and validation lessons.
FAIT a€” rr_read_batch accepte jusqu a 64 elements et decoupe au-dela d un budget 0xF000. Meme section.
FAIT a€” La reponse place les donnees a l offset zero, puis un octet de statut par element, et remplace l en-tete de requete. Meme section.
FAIT a€” Le client recopie les elements reussis et rend leur nombre. Un compte positif ne signifie pas que tout a ete recopie. Meme section.
FAIT a€” Les lectures ne sont pas un instantane atomique d Unity. README.md section How one frame works.FAIT a€” Une lecture ratee signifie inconnu, pas collection vide ni cible absente. Meme section.
FAIT a€” METHOD_BUFFERED reutilise le tampon systeme pour requete et reponse, le pilote copie les champs avant ecrasement. BUILD.md section Build the driver.

## Donnees lues ou ecrites
Lit et ecrit : memoire du processus cible. Ecrit aussi : tampon de reponse du pilote.

## Reglages
Plafond de 64 Kio par requete. Plafond de 64 elements par lot. Budget de decoupage 0xF000.

## Dependances
rr_mem.c, wm_drv.c, contrat d IOCTL partage.

## Points de rupture
Un patch du jeu deplace les champs, les lots lisent du vide sans erreur franche.
Le contrat de reponse doit rester aligne entre client et pilote : toute retouche d un cote casse l autre. BUILD.md section Build the driver.
Un statut par element non verifie fait passer une lecture partielle pour complete.

## Inconnus
Numero d IOCTL et structures de requete. Statut remonte par element.
Valeur de retour de rr_read sur echec.

## Sources
README.md sections How one frame works et Memory and validation lessons. BUILD.md section Build the driver.

## Ancres de ligne
- rr_mem.c:400, avertissement C4267 de compilation, docs/DEFAUTS.md:15
- rr_mem.c:421, second avertissement C4267, docs/DEFAUTS.md:15
- README.md, section Memory and validation lessons, sans numero de ligne
