# Registre des defauts

Etat au 2026-11-23. Gravite: 1 bloquant, 2 genant, 3 mineur.
Un defaut ferme reste liste avec sa date de fermeture: il documente une decision, pas un oubli.

| ID | Defaut | Effet | Gravite | Etat |
|---|---|---|---|---|
| D01 | `bind.dat` n est pas signe et peut etre supprime | Effacer le fichier remet la place a zero; une copie registre le compense, effacer les deux remet la place a zero | 1 | attenue 2026-11-23 |
| D02 | L anti-recul ecrit sous HKLM | Si le processus n est pas eleve, l ecriture echoue et le controle est inoperant | 2 | ferme 2026-11-23: les deux exe exigent administrator par manifeste |
| D03 | Aucun flux d activation | L empreinte se lit a la main dans le registre ou dans la fenetre de refus | 2 | classe 2026-11-23: vente en joker, l acheteur ne fournit jamais son empreinte |
| D04 | L empreinte derive du MachineGuid | Reinstallation de Windows = nouveau jeton obligatoire | 2 | assume |
| D05 | Aucun avertissement d expiration | Refus brutal au 31e jour, sans preavis | 2 | ouvert |
| D06 | Binaire non signe | SmartScreen, antivirus, confiance de l acheteur | 2 | assume |
| D07 | Build non reproductible | Pas de /Brepro, /GL, /LTCG: deux builds donnent deux hachages | 3 | ouvert |
| D08 | Warnings de compilation preexistants | C4267 rr_mem 400 et 421, C4013 rr_aim 33, C4005 gpu.cpp 8, C4101 rr_exp 963 | 3 | ouvert |
| D09 | Messages en francais non accentues | Rendu console, lisibilite | 3 | assume |
| D10 | `README.md` racine decrit encore l ancienne architecture | Un lecteur neuf se trompe de chaine | 3 | ouvert |
| D11 | Aucune revocation | Une cle qui fuit reste valable jusqu a expiration | 2 | assume |
| D12 | Codes 5 et 10 ont le meme texte | L acheteur ne distingue pas fichier d une autre machine et place deja prise | 3 | ouvert |
| D13 | Jeton joker jamais converti en jeton lie | `licence.dat` reste identique partout; seule la place est consommee | 3 | assume |
| D14 | Contournement par `START.bat` | Les deux scripts lancent le meme binaire, donc la porte s applique | 3 | ferme 2026-11-23 |
| D15 | Pas de desinstallation | Restes dans `%LOCALAPPDATA%\Dreww` et sous HKLM apres arret | 3 | ouvert |
