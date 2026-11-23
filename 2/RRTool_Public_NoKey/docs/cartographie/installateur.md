# Installateur

## But

Copier le produit dans C:\Dreww, poser la licence, couper l hyperviseur, creer le raccourci, redemarrer.

## Ou ca vit

- INSTALLER.cmd:1-4 a€” lanceur a double-clic.
- INSTALLER.ps1:1-88 a€” script complet.

## Comment ca marche

FAIT a€” INSTALLER.cmd force le repertoire du script puis appelle INSTALLER.ps1 en politique Bypass, en transmettant les arguments. INSTALLER.cmd:2-4.
FAIT a€” INSTALLER.ps1 s eleve lui-meme en RunAs si le jeton n est pas administrateur. INSTALLER.ps1:9-20.
FAIT a€” Garde-fou : arret si 1_run\RobRunPort.exe est absent, message Â« Ce script doit rester dans le dossier livre Â». INSTALLER.ps1:26-30.
FAIT a€” Etape 1 : creation de C:\Dreww, puis robocopy de 1_run, setup et docs en /E. INSTALLER.ps1:32-34.
FAIT a€” Trois documents internes exclus de la copie : PROCEDURE_LICENCES.md, DEFAUTS.md, RISQUES.md. INSTALLER.ps1:35.
FAIT a€” Code robocopy superieur ou egal a 8 traite comme echec et arret. INSTALLER.ps1:36-40.
FAIT a€” INSTALLER.ps1 et INSTALLER.cmd recopies a la racine de la destination. INSTALLER.ps1:42-43.
FAIT a€” Etape 2 : selecteur de fichier, copie vers %LOCALAPPDATA%\Dreww\licence.dat. INSTALLER.ps1:45-55.
FAIT a€” Copie sur soi-meme evitee par comparaison de chemins. INSTALLER.ps1:55.
FAIT a€” Etape 3 : appel de setup\1_couper_hyperviseur.ps1 avec -NoReboot, controle du code retour. INSTALLER.ps1:65-69.
FAIT a€” Etape 4 : raccourci bureau Dreww.lnk vers 1_run\FFLoader.exe, repertoire de travail C:\Dreww. INSTALLER.ps1:74-79.
FAIT a€” Sans -NoReboot, redemarrage dans 20 secondes. INSTALLER.ps1:86-87.
DECISION 2026-11-23 a€” Le raccourci vise FFLoader.exe et non START.bat, qui ne mappe pas le driver. JOURNAL entree Â« Installation validee de bout en bout Â».

## Donnees lues ou ecrites

- Ecrit : C:\Dreww, %LOCALAPPDATA%\Dreww\licence.dat, raccourci bureau, entree de redemarrage.
- Lit : 1_run\RobRunPort.exe en garde-fou, setup\1_couper_hyperviseur.ps1.

## Reglages

- Parametre -NoReboot : supprime le redemarrage. INSTALLER.ps1:4, 82-85.

## Dependances

- setup/1_couper_hyperviseur.ps1 a€” doit etre present, sinon etape sautee avec avertissement. INSTALLER.ps1:70-72.
- 1_run/FFLoader.exe a€” cible du raccourci.
- System.Windows.Forms, WScript.Shell, robocopy.

## Points de rupture

- Le garde-fou porte sur RobRunPort.exe alors que le raccourci lance FFLoader.exe. Si 1_run change de contenu, le test reste vert et le raccourci peut viser un fichier absent.
- Le nom du dossier de destination est en dur. INSTALLER.ps1:7.
- La liste d exclusion est en dur. Un nouveau document interne non ajoute a INSTALLER.ps1:35 part chez l acheteur.
- Un refus d elevation laisse le script sortir sans message. INSTALLER.ps1:18-19.
- Deux lignes de confirmation pour une seule action, Â« licence en place Â» puis Â« licence installee Â». INSTALLER.ps1:56-57.

## Inconnus

- Aucun test du cas Â« selecteur annule Â» au-dela du message. INSTALLER.ps1:61-63.

## Sources

INSTALLER.ps1:1-88 ; INSTALLER.cmd:1-4 ; JOURNAL_AGENT.txt entrees Â« Installateur durci et teste Â», Â« Installation validee de bout en bout Â» ; docs/INSTALLATION_CLIENT.md:22-28.
