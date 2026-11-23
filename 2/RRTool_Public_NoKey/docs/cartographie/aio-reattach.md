# Attente de menu et reattachement

## But
Demarrer l overlay au menu principal, et le relancer quand aucune donnee n arrive.
## Ou ca vit
- BUILD.md section Menu wait and reattach
- RobRunAIO.ini, cles de reglage

## Comment ca marche
FAIT a€” L overlay n est pas lance pendant le demarrage du moteur. BUILD.md section Menu wait and reattach.
FAIT a€” Le lanceur attend la fenetre de jeu, puis un delai de stabilisation. Meme section.
FAIT a€” Il lit ensuite status.log : en match, visible, non minimisee, sans instantane de joueurs dans le delai, l overlay est termine et relance. Meme section.
FAIT a€” robrun_runtime.txt est mis de cote pour forcer un balayage propre. Meme section.
FAIT a€” La derniere instance est laissee en place quand les tentatives sont epuisees. Meme section.
FAIT a€” Cles : menu_wait_window 1, menu_delay 30, attach_timeout 60, reattach_attempts 3. Meme section.
FAIT a€” Drapeaux --no-menu-wait, --menu-delay, --attach-timeout, --reattach-attempts, --dry-run, --no-map. Meme section.

## Donnees lues ou ecrites
Lit : status.log, fenetre de jeu. Ecrit : status.log, robrun_runtime.txt mis de cote.

## Reglages
Les cinq cles et les drapeaux equivalents.

## Dependances
status.log, detection de fenetre, RobRunAIO.ini.

## Points de rupture
Un status.log muet fait boucler les relances jusqu a epuisement.
Un delai trop court vise un monde non charge.

## Inconnus
Contenu exact de status.log exploite par le lanceur. Critere de visibilite.

## Sources
BUILD.md section Menu wait and reattach et tableau des reglages.

## Ancres de ligne
- aio_launcher.c:1206-1213, mise de cote et suppression du cache, citees par sonde
- BUILD.md, section Menu wait and reattach, sans numero de ligne
