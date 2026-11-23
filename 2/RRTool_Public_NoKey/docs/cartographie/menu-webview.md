# Hote WebView2

## But
Afficher la page de menu dans une fenetre WebView2 et relier ses messages au schema.
## Ou ca vit
- 2_src_port/menu_webview.cpp, 16367 octets, non lu
- 2_src_port/wv2_cb.h, wv2_cb_impl.h
- 2_src_port/WebView2SDK, embarque

## Comment ca marche
FAIT a€” menu_webview.cpp et menu.html se lisent ensemble pour suivre un curseur du message de page au reglage valide puis a l etat serialise. README ordre de lecture point 6.
FAIT a€” Les rappels COM sont dans wv2_cb.h et wv2_cb_impl.h. README carte des sources.
FAIT a€” Le SDK est embarque et sa licence doit etre conservee. README section Source map.
FAIT a€” WebView2Loader.dll doit rester a cote de l exe. BUILD.md:42-43.
FAIT a€” Un menu blanc s inspecte par runtime WebView2, DLL de chargement et wv2_error.log. README section Interpreting failures.

## Donnees lues ou ecrites
Ecrit : wv2_error.log. Lit : ressource 101.

## Reglages
Aucun reglage propre.

## Dependances
WebView2SDK, WebView2Loader.dll, runtime WebView2 installe.

## Points de rupture
Runtime absent, menu blanc.
DLL absente, echec de chargement.

## Inconnus
Tout le corps du fichier et des rappels. Format des messages.

## Sources
README ordre de lecture point 6, carte des sources, section Interpreting failures. BUILD.md:42-43.
