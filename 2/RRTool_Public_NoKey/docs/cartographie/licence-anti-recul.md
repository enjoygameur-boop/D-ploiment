# Anti-recul d horloge

## But
Refuser un jeton valide presente avec une horloge reculee, pour empecher de prolonger une duree par ce moyen.

## Ou ca vit
- JOURNAL_AGENT.txt entree Â« licence Â» (mecanisme et ordre).
- docs/DEFAUTS.md:9 (D02, ferme).
- 2_src_port/licence.c, non lu.

## Comment ca marche
FAIT a€” Valeur Seen sous HKLM\SOFTWARE\Dreww, niveau 2. JOURNAL entree Â« licence Â».
FAIT a€” Refus au dela de 24 h de recul. JOURNAL entree Â« licence Â».
FAIT a€” Signature verifiee avant toute avance de Seen. JOURNAL entree Â« licence Â».
FAIT a€” Code de refus 7, horloge. docs/INSTALLATION_CLIENT.md:51.
FAIT a€” Les deux exe demandent administrator par manifeste, l ecriture HKLM est donc toujours possible. docs/DEFAUTS.md:9.
DECISION 2026-11-23 a€” D02 ferme par les manifestes. docs/DEFAUTS.md:9.

## Contradiction
docs/DEFAUTS.md:9 donne D02 ferme ; JOURNAL entree Â« licence Â» note encore Â« Codes 2 et 9 non provoques Â». Ce sont deux sujets voisins, pas un desaccord.

## Donnees lues ou ecrites
Lit et ecrit : valeur Seen sous HKLM\SOFTWARE\Dreww.

## Reglages
Seuil fixe de 24 h. Aucun reglage d execution.

## Dependances
licence.c, HKLM, elevation par manifeste.

## Points de rupture
Un exe sans manifeste administrateur rend le controle inoperant. docs/DEFAUTS.md:9.
Une horloge remise a l heure par l acheteur remonte Seen sans difficulte. Deduit du seuil, non ecrit.
Un recul sous 24 h passe. Deduit du seuil.

## Inconnus
Format et emplacement de la valeur Seen. Type de stockage.
Comportement quand HKLM est absent ou en lecture seule.

## Sources
JOURNAL_AGENT.txt entree Â« licence Â». docs/DEFAUTS.md:9. docs/INSTALLATION_CLIENT.md:51.