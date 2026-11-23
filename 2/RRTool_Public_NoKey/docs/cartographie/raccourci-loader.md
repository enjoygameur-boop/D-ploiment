# Raccourci et passage par le loader

## But

Faire passer le lancement par DrewwLoader.exe, seul chemin qui mappe le driver, avec l elevation portee par le raccourci.

## Ou ca vit

- INSTALLER.ps1:74-79 a€” creation du raccourci.
- docs/INSTALLATION_CLIENT.md:36 a€” consigne d usage.
- 1_run/DrewwLoader.exe a€” cible, binaire hors perimetre sauf hachage.
- 5_src_loader/loader.cpp a€” source du loader, non lue.

## Comment ca marche

FAIT a€” Le raccourci se nomme Dreww.lnk, pointe 1_run\DrewwLoader.exe, repertoire C:\Dreww. INSTALLER.ps1:76-78.
FAIT a€” Le document client interdit de lancer RobRunPort.exe directement et deconseille START.bat. docs/INSTALLATION_CLIENT.md:36.
FAIT a€” Le document client demande de ne pas desactiver le raccourci, qui porte l elevation. docs/INSTALLATION_CLIENT.md:61.
FAIT a€” DrewwLoader.exe existe sous 5_src_loader et sous 1_run. Arbre Git.
DECISION 2026-11-23 a€” Le raccourci a d abord vise START.bat, corrige vers DrewwLoader.exe. JOURNAL entree Â« Installation validee de bout en bout Â».

## Contradiction

JOURNAL entree Â« Installateur durci et teste Â» dit Â« raccourci vers 1_run\START.bat Â». L entree suivante, meme jour, dit Â« il vise DrewwLoader.exe Â». La seconde est la plus recente et correspond au code. INSTALLER.ps1:77 confirme DrewwLoader.
docs/DEFAUTS.md:21 (D14) classe le contournement START.bat comme ferme, alors que docs/INSTALLATION_CLIENT.md:36 le deconseille encore.

## Donnees lues ou ecrites

- Ecrit : Dreww.lnk sur le bureau.
- Lit : chemin de 1_run\DrewwLoader.exe.

## Reglages

Aucun.

## Dependances

- DrewwLoader.exe doit etre present dans 1_run au moment de l installation.
- Le manifeste de DrewwLoader demande l elevation, sinon le pilote ne se mappe pas.

## Points de rupture

- Si DrewwLoader.exe est renomme ou deplace, le raccourci casse sans message.
- Le loader est hors perimetre de lecture : son contrat d appel n est pas verifie ici.

## Inconnus

- Comportement de DrewwLoader quand la licence manque. INCONNU, non documente.

## Sources

INSTALLER.ps1:74-79 ; docs/INSTALLATION_CLIENT.md:36, 61 ; JOURNAL_AGENT.txt entrees Â« Installateur durci et teste Â», Â« Installation validee de bout en bout Â».
