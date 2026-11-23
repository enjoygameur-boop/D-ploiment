# Dreww - installation client

Suis les etapes dans l ordre. Une etape ratee donne un refus au lancement, pas un plantage: lis le code affiche.

## 1. Ce qu il te faut

- Windows 10 ou 11, 64 bits, a jour.
- Droits administrateur.
- Le runtime WebView2 (fourni d origine sur Windows 11).
- Le dossier livre apres achat et ton fichier licence.dat.

## 2. Windows Defender

Coupe-le avant de lancer l installateur, il bloque le pilote. Telecharge Defender Control de Sordum:

https://www.sordum.org/9480/defender-control-v2-1/

Decompresse, lance `dControl.exe` en administrateur, clique **Disable Windows Defender**, referme.

## 3. Lancer l installateur

Double-clic sur `INSTALLER.cmd`. Il s eleve seul et enchaine tout:

- copie du produit dans `C:\Dreww`;
- fenetre de choix: designe ton `licence.dat`, il l installe lui-meme au bon endroit;
- coupure de l integrite de la memoire, de l hyperviseur, de Hyper-V, WSL2, Sandbox et Docker;
- raccourci Dreww sur le bureau;
- redemarrage.

Ne ferme pas la fenetre avant la fin. Si tu choisis un autre fichier que `licence.dat`, l installation continue mais la licence manquera.

## 4. Apres le redemarrage

Double-clic sur le raccourci **Dreww**. Il demande l elevation, accepte.

Ne lance pas `RobRunPort.exe` directement et ne te fie pas a `START.bat`: seul le raccourci passe par le loader, qui mappe le driver.

## 5. SmartScreen

Le binaire n est pas signe. Au premier lancement: **Informations complementaires**, puis **Executer quand meme**.

## 6. Si le lancement est refuse

La fenetre donne un code et l empreinte de la machine:

- 1: licence.dat introuvable. Relance l installateur et choisis le fichier.
- 2: fichier illisible. Re-telecharge la piece jointe.
- 3: jeton mal forme. Fichier tronque: redemande-le.
- 5: licence liee a une autre machine.
- 6: licence expiree.
- 7: horloge reculee. Remets l heure automatique.
- 8: signature invalide. Fichier altere: redemande-le.
- 9: crypto indisponible. Redemarre et relance.
- 10: licence deja liee a une autre machine, place unique.

Envoie le code et l empreinte au support, pas le fichier.

## 7. Regles

- Garde le dossier `C:\Dreww` et le dossier de licence en place tant que la licence court.
- Ne desactive pas le raccourci: il porte l elevation necessaire au pilote.
