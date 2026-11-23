# Page de menu

## But
Fournir l interface des reglages, embarquee dans l executable.
## Ou ca vit
- 2_src_port/menu.html, 147179 octets
- 2_src_port/app.rc, embarquement
- menu.html:401, 519, 576-577, exemples

## Comment ca marche
FAIT a€” Le fichier est compile dans l exe par app.rc a chaque build_port. _scratch/HANDOFF_aim_suivant.txt Â§2.
FAIT a€” Le menu est charge depuis la ressource 101 RCDATA, jamais depuis un fichier libre. BUILD.md section Menu edits.
FAIT a€” Les controles portent un attribut data-key reprenant le nom du reglage. menu.html:401, 519.
FAIT a€” La legende emploie les memes couleurs que le rendu. menu.html:576-577.
FAIT a€” Un reglage de visee porte un label et une case. menu.html:519.
INCONNU a€” structure des sections, feuille de style, script de liaison.

## Donnees lues ou ecrites
Ecrit : etat des controles. Lit : valeurs injectees.

## Reglages
Tous les reglages de menu_bridge.h.

## Dependances
app.rc, menu_webview.cpp, menu_bridge.h.

## Points de rupture
Un data-key renomme sans le schema casse le reglage silencieusement.
Un HTML modifie sans rebuild n atteint pas le binaire. BUILD.md section Menu edits.

## Inconnus
Organisation des sections. Script embarque.

## Sources
menu.html:401, 519, 576-577. BUILD.md section Menu edits. _scratch/HANDOFF_aim_suivant.txt Â§2.
