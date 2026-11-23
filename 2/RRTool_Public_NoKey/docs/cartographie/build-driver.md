# Build du pilote noyau

## But
Compiler driver.sys depuis wm_drv.c.

## Ou ca vit
- BUILD.md:88-99, section Build the driver
- 3_src_driver/build_driver.bat, non lu
- 3_src_driver/wm_drv.c, wm.h, non lus

## Comment ca marche
FAIT a€” Push-Location .\3_src_driver, cmd /c build_driver.bat, Pop-Location. BUILD.md:90-94.
FAIT a€” MSVC appele avec /kernel et lie les bibliotheques WDK x64. BUILD.md:96.
FAIT a€” Sortie x64/Release/driver.sys recopiee vers 3_src_driver/driver.sys. BUILD.md:97-98.FAIT a€” Le script imprime les commandes de deploiement sans les executer. BUILD.md:98-99.
FAIT a€” Compiler ne charge pas le pilote. BUILD.md:99.
FAIT a€” Le script prefere WDK/SDK 10.0.26100.0, avec repli par recherche d include. BUILD.md:21-23.
FAIT a€” x64 et driver.sys ignores par Git. .gitignore:4-5.
FAIT a€” Le pilote est distribue sous deux noms, driver.sys et kernel-mode.sys. BUILD.md section Runtime artifact map.

## Donnees lues ou ecrites
Lit : wm_drv.c, wm.h, en-tetes WDK. Ecrit : x64/Release/driver.sys, 3_src_driver/driver.sys.

## Reglages
Version de SDK preferee en dur. BUILD.md:22.

## Dependances
WDK et en-tetes noyau. BUILD.md:14.
Coherence en-tetes et bibliotheques x64. BUILD.md:23.

## Points de rupture
Pilote reconstruit, hachage controle par le lanceur change. BUILD.md section Masquerade.
Une image mappee survit au rebuild et a la fermeture de l overlay, seul un redemarrage la retire. BUILD.md section Build the driver.
Le dechargement retire le lien symbolique sans demapper. Meme section.
Pilote non signe cote produit. docs/DEFAUTS.md:14 (D06).

## Inconnus
Contenu de build_driver.bat, controles reels, options de signature.

## Sources
BUILD.md:14-23, 88-99. .gitignore:4-5. docs/DEFAUTS.md:14.
