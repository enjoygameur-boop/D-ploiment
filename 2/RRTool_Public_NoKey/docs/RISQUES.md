# Registre des risques

Etat au 2026-11-23. Probabilite et impact: 1 faible, 2 moyen, 3 fort.

| ID | Risque | Prob | Impact | Parade |
|---|---|---|---|---|
| R01 | Mise a jour du jeu, offsets morts | 3 | 3 | Veille sur les patchs, version de jeu annoncee sur la fiche, correctif avant revente |
| R02 | Detection par l anticheat | 2 | 3 | Driver deja masque, test sur compte neuf, consigne de lancement strict |
| R03 | Jeton partage entre acheteurs | 2 | 2 | Liaison unique, texte explicite a la vente |
| R04 | Jeton fuit et diffuse | 2 | 3 | Duree courte, serie par jeton pour identifier la source |
| R05 | Reinstallation de Windows | 3 | 2 | Annonce claire, remplacement de jeton sur ticket |
| R06 | Antivirus qui supprime le binaire | 2 | 2 | Sordum Defender Control, exclusions, archive non compressee signalee |
| R07 | SmartScreen bloque l acheteur | 3 | 2 | Procedure en 2 clics dans le document, capture d ecran |
| R08 | Windows reactive l integrite de la memoire | 2 | 3 | Script `setup\1_couper_hyperviseur.ps1`, rappel apres chaque grosse mise a jour |
| R09 | WebView2 absent | 1 | 2 | Lien d installation dans les prerequis |
| R10 | Perte de `_licence/private.p8` | 1 | 3 | Copie hors machine, coffre, et test de signature apres restauration |
| R11 | Fuite du depot prive | 1 | 3 | Acces restreint, offsets non publies |
| R12 | Pas de sauvegarde de la cle privee | 2 | 3 | Copie chiffree sur support externe des maintenant |
| R13 | Dependance a un seul buildeur | 2 | 2 | Procedure de build ecrite dans BUILD.md |
| R14 | Suivi des ventes manuel | 3 | 2 | Journal des series dans `_licence`, une ligne par vente |
| R15 | Remboursement apres ban | 2 | 2 | Conditions ecrites avant paiement |
