# RAGE - INVENTAIRE ET BASE PROPRE

## Faits etablis
- Chaine battle : updater+0x70 -> BattleModel
- battle+0x40 -> pointeur PlayerRotationInputModel ; yaw +0x10, pitch +0x14, quaternion +0x20, radians
- Vecteur stocke par le jeu : (sin yaw, -sin pitch, cos yaw). Pitch positif vers le bas
- Ecrire le yaw fait pivoter la vue et deplace les impacts : rot pilote camera et tir
- Site manuel A95D2F : movups [rsp+0x50],xmm0 / mov [rsp+0x58],eax / call rel32 (12 octets)
- Site auto A86FF0 (18 octets)
- battle+0x198 AimTargetModel ; +0x10 CharacterId ; +0x14 TargetType (3 = personnage) ; aim+0x38 = PlayerRotationInput
- BattleCharacterModel.LookDirection = 0x70 est un POINTEUR ; LookDirectionModel _value 0x10, _yaw 0x1C, _pitch 0x20
- 0x48A1EB0 raycast direction ; 0x48A1F80 position d'impact
- game+0x58 SensitivityModel ; PlayerPreferenceValue 0x10 ; PlayerPreferenceAimValue 0x14
- No spread valide : char+0x10 -> +0x220 -> +0x20/+0x24

## Ce qui fonctionne
- Ecriture de rot a l'appui : vue qui pivote, impacts qui suivent
- Pose de hook avec verification d'octets, table de restauration, rejeu : stub execute, compteur monte
- Calcul d'angle vers la cible : numeriquement juste
- Lectures ESP, snapshots, position camera

## Ce qui ne fonctionne pas
- CharacterId seul avec drapeau 1 : aucune balle
- Injection d'un vecteur a rsp+0x50 ou rbx+0x70 : impacts inchanges
- Hook S3
- Ecriture de rot recalculee chaque frame : boucle de retroaction, camera qui derive

## Ce qui provoque un crash
- Patch residuel apres fermeture de l'overlay : saut dans une memoire liberee
- Stub alloue par le driver : memoire liberee avec l'overlay
- Ecriture de 3 floats par-dessus rbx+0x70 qui est un pointeur : bugcheck 0x1E
- Mauvais decalage de pile sur la voie auto (rsp+0x50 au lieu de rsp+0x58)
- Driver deja mappe : kd2 refuse

## Ce qui ne provoque pas de crash
- Lectures seules, dumps, snapshots
- Ecritures rot avec origine gelee
- Jeu sans overlay apres redemarrage

## Regles de reconstruction
1. Demarrer sans patch de code : uniquement des ecritures de donnees (rot, LookDirection, AimTarget)
2. Allocation d'execution par VirtualAllocEx dans le jeu, jamais le driver
3. Un hook par site, octets verifies, restauration a chaque demarrage
4. Un compteur par site, log de tout ce qui est lu et ecrit
5. Un build par iteration, redemarrage du jeu apres chaque build
6. Un mapping driver par demarrage

## Inconnues
- Ou le tir lit reellement sa direction : desassembler 0x48A1EB0
- Si LookDirection est consommee au tir ou seulement pour l'animation
- Tolerance EAC sur les ecritures de donnees pures