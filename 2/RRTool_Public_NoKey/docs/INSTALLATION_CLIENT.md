# Dreww - installation client

Suis les etapes dans l ordre, sans en sauter. Une etape ratee donne un refus au lancement, pas un plantage: lis le code affiche.

## 1. Ce qu il te faut

- Windows 10 ou 11, 64 bits, a jour.
- Droits administrateur (le loader les demande).
- Le runtime WebView2 (fourni d origine sur Windows 11; sur Windows 10, installe-le depuis le site de Microsoft s il manque).
- Le dossier livre apres achat: loader, AIO, configs, dossier setup, licence.dat, ce document.

## 2. Integrite de la memoire

Parametres > Confidentialite et securite > Securite Windows > Securite du peripherique > Details sur l isolation du noyau: mets **Integrite de la memoire** sur Desactive, puis redemarre.

Si l option est grisee ou revient toute seule, ne t acharne pas: l etape 4 s en occupe par le registre.

## 3. Windows Defender

Le pilote est souvent bloque par Defender. Coupe-le avec Defender Control de Sordum:

https://www.sordum.org/9480/defender-control-v2-1/

Telecharge, decompresse, lance `dControl.exe` en administrateur, clique sur **Disable Windows Defender**. Referme l outil.

Rien a faire de plus: la decision tient apres redemarrage. Pour rendre Defender plus tard, relance l outil et clique sur Enable.

## 4. Couper l hyperviseur

Dans le dossier setup, clic droit sur `1_couper_hyperviseur.ps1`, **Executer avec PowerShell**. Le script s eleve seul et demande confirmation a l ecran d utilisateur.

Il coupe l integrite de la memoire par le registre, l hyperviseur au demarrage, Hyper-V, la plateforme machine virtuelle, la plateforme de l hyperviseur, WSL2, la sandbox Windows, les services de virtualisation et Docker, puis redemarre au bout de 15 secondes.

Si tu vis avec WSL2 ou Docker au quotidien, sache que tu devras les remettre en route apres, avec `bcdedit /set hypervisorlaunchtype auto` et la reinstallation des fonctionnalites.

## 5. Creer le dossier de licence

Dans le dossier setup, clic droit sur `2_creer_dossier.ps1`, **Executer avec PowerShell**. Le script cree `%LOCALAPPDATA%\Dreww` et ouvre le dossier dans l explorateur.

Pas besoin d administrateur pour celui-ci.
## 6. Deposer la licence

Place le fichier `licence.dat` recu apres achat dans le dossier ouvert a l etape 5, sans le renommer et sans l ouvrir.

Chemin complet typique: `C:\Users\<ton nom>\AppData\Local\Dreww\licence.dat`

Ne le deplace pas ailleurs: le loader cherche exactement la.

## 7. Lancer

Installe le dossier du produit dans un chemin fixe, par exemple `C:\Dreww`. Evite le Bureau, les telechargements et OneDrive: les chemins qui bougent cassent le loader.

Clic droit sur `1_run\START.bat`, **Executer en tant qu administrateur**. Ne lance pas `RobRunPort.exe` directement: il demarre sans le contexte du loader.

## 8. SmartScreen

Le binaire n est pas signe. Au premier lancement, Windows affiche « Windows a protege votre PC ». Clique sur **Informations complementaires**, puis **Executer quand meme**. La decision est memorisee pour ce fichier.

Si Defender est revenu entre temps, ajoute `C:\Dreww` et le dossier `%LOCALAPPDATA%\Dreww` en exclusion.

## 9. Si le lancement est refuse

La fenetre donne un code et l empreinte de la machine:

- 1: `licence.dat` introuvable. Reprends l etape 6, verifie le nom exact et le dossier.
- 2: fichier illisible. Re-telecharge la piece jointe, ne le recopie pas a la main.
- 3: jeton mal forme. Le fichier a ete tronque ou modifie: redemande-le.
- 5: licence liee a une autre machine. Ta place est deja prise.
- 6: licence expiree.
- 7: horloge reculee. Remets l heure automatique dans Windows.
- 8: signature invalide. Fichier altere: redemande-le.
- 9: crypto indisponible. Redemarre, puis relance.
- 10: licence deja liee a une autre machine, place unique. Meme reponse que le 5.

Envoie le code et l empreinte au support, pas le fichier.

## 10. Regles

- Garde le dossier du produit et le dossier de licence en place tant que la licence court.
