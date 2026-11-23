# Generation et audit des offsets

## But
Regenerer les en-tetes d offsets depuis un dump et auditer les ecarts.
## Ou ca vit
- BUILD.md section Understand the offset inputs
- outils absents du depot : gen_offsets.py, sdk_offsets.py, audit_unityentry_offsets.py

## Comment ca marche
FAIT a€” Les outils consomment des entrees absentes du dossier public. BUILD.md section Understand the offset inputs.
FAIT a€” Entrees de gen_offsets.py : types.csv, fields.csv, methods.csv, manifest.json et GameAssembly.dll, le hash du manifeste etant verifie. Meme section.
FAIT a€” --header est obligatoire, le defaut legacy pointe sous un dossier 2_src_cheat absent. Meme section.
FAIT a€” Le rapport va dans offsets/robrun_offsets.json. Meme section.
FAIT a€” sdk_offsets.py consomme Models.hpp, Battle.hpp, Game.hpp, Global.hpp et DumpManifest.sha256 du dossier parent. Meme section.
FAIT a€” --check compare sans ecrire. Meme section.
FAIT a€” L audit compare les champs entre les deux en-tetes, verifie les empreintes et optionnellement le hash du binaire. Meme section.
FAIT a€” Les comptes de votes ne designent pas une instance active. Meme section.
FAIT a€” Les offsets Unity natifs, charges generiques, corps de methodes et identites vivantes demandent une verification separee. Meme section.

## Donnees lues ou ecrites
Lit : dump, binaire. Ecrit : en-tetes, JSON de rapport.

## Reglages
--root, --dump, --header, --sdk, --check, --binary.

## Dependances
Python 3, dump complet, binaire correspondant.

## Points de rupture
Dump ou binaire non concordants, hash rejete.
Un champ manquant passe inapercu sans revue manuelle.

## Inconnus
Corps des trois outils. Version de dump acceptee.

## Sources
BUILD.md section Understand the offset inputs.

## Ancres de ligne
- _scratch/MAINTENANCE_fast_scan.txt:1, procedure de refection par dump apres mise a jour
- offsets/robrun_offsets.json, rapport de generation, sans numero de ligne
- BUILD.md, section Understand the offset inputs, sans numero de ligne
