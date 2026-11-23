# Build de l overlay

## But
Compiler RobRunPort.exe et le deployer dans 1_run.

## Ou ca vit
- BUILD.md:25-55, section Build the overlay
- 2_src_port/build_port.bat, non lu
- .gitignore:2-4, sorties ignorees
- 2_src_port/app.rc, embarquement des ressources
## Comment ca marche
FAIT a€” Push-Location, cmd /c build_port.bat, Pop-Location. BUILD.md:29-33.
FAIT a€” Sortie recopiee vers 1_run/RobRunPort.exe. BUILD.md:35.
FAIT a€” Point d entree WinMain dans rr_esp.c. BUILD.md:36.
FAIT a€” rr_main.c hors de ce build. BUILD.md:36-37.
FAIT a€” rc.exe embarque menu.html et app.manifest dans app.res. BUILD.md:39.
FAIT a€” Options /O2 /W3 /MT et /EHsc, runtime statique. BUILD.md:41-42.
FAIT a€” WebView2Loader.dll.lib au lien, la DLL reste a cote de l exe. BUILD.md:42-43.
FAIT a€” Aucun HTML libre au runtime. BUILD.md:44-45.
FAIT a€” Deux minutages de decouverte modifies dans rr_game.c. BUILD.md:52-55.
FAIT a€” Sorties ignorees par Git, copies de retour conservees dans 1_run. .gitignore:2-4, BUILD.md:48-50.

## Donnees lues ou ecrites
Lit : sources C et C++, menu.html, app.manifest, WebView2SDK.
Ecrit : *.obj, app.res, RobRunPort.exe, copie dans 1_run.

## Reglages
Aucun reglage de build. Detection de Visual Studio en dur. BUILD.md:18-20.

## Dependances
MSVC x64 et Windows SDK. BUILD.md:11.
WebView2SDK embarque. BUILD.md:13.
vcvars64.bat. BUILD.md:19.

## Points de rupture
Patch du jeu, offsets compiles perimes, build vert quand meme. README.md section Interpreting failures.
DLL WebView2Loader absente, menu blanc. Meme section.
Le build ne rafraichit pas 1_run\payload. _scratch/HANDOFF_suivant.txt Â§5.
Detection limitee a VS 18 et 2022 Community et Professional. BUILD.md:18-20.

## Inconnus
Contenu de build_port.bat : unites compilees, ordre, options reelles.

## Sources
BUILD.md:18-55. .gitignore:2-4. README.md section Interpreting failures. _scratch/HANDOFF_suivant.txt Â§5.
