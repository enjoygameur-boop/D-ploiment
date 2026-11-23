# Colis client

## But

Definir ce qui part chez l acheteur et ce qui reste interne.

## Ou ca vit

- INSTALLER.ps1:34-35 a€” dossiers copies et fichiers exclus.
- docs/INSTALLATION_CLIENT.md:22-28 a€” description publique du contenu installe.
- docs/PROCEDURE_LICENCES.md:3 a€” marquage Â« jamais livre Â».

## Comment ca marche

FAIT a€” Seuls 1_run, setup et docs sont copies. INSTALLER.ps1:34.
FAIT a€” PROCEDURE_LICENCES.md, DEFAUTS.md et RISQUES.md sont exclus. INSTALLER.ps1:35.
FAIT a€” PROCEDURE_LICENCES.md se declare interne. docs/PROCEDURE_LICENCES.md:3.
FAIT a€” docs/branding n est pas exclu : il suit la copie de docs. INSTALLER.ps1:34-35.
FAIT a€” 2_src_port, 3_src_driver, 4_src_mapper, 5_src_loader, offsets et _licence ne sont pas copies. INSTALLER.ps1:34.
DECISION 2026-11-23 a€” Les documents internes sont exclus du colis. JOURNAL entree Â« Installateur durci et teste Â».

## Contradiction

JOURNAL entree Â« Installateur durci et teste Â» annonce Â« docs reduits a INSTALLATION_CLIENT.md Â». Le code exclut trois fichiers mais laisse passer docs/branding/overlay.png. Le resultat reel contient donc aussi une image.

## Donnees lues ou ecrites

- Lit : arborescence source.
- Ecrit : arborescence C:\Dreww.

## Reglages

Aucun.

## Dependances

- robocopy, filtre /XF.

## Points de rupture

- Un document interne cree plus tard sans etre ajoute a INSTALLER.ps1:35 est livre.
- Le colis ne contient aucune source : une reprise depuis un colis installe se fait sans code.

## Inconnus

- Sort de _licence cote colis : jamais copie, donc la cle privee ne part jamais. Deduit de INSTALLER.ps1:34, non ecrit explicitement.

## Sources

INSTALLER.ps1:34-35 ; docs/INSTALLATION_CLIENT.md:22-28 ; docs/PROCEDURE_LICENCES.md:3 ; JOURNAL_AGENT.txt entree Â« Installateur durci et teste Â».
