# Signature du jeton

## But
Rendre un jeton infalsifiable sans serveur : cle privee pour signer, cle publique compilee pour verifier.

## Ou ca vit
- docs/PROCEDURE_LICENCES.md:7-13
- JOURNAL_AGENT.txt entree Â« licence Â»
- 2_src_port/licence.c, non lu
- _licence/private.p8, public.ec, q.hex

## Comment ca marche
FAIT a€” Paire ECDSA P-256. JOURNAL entree Â« licence Â».
FAIT a€” Verification BCrypt sur blob public ECS1. JOURNAL entree Â« licence Â».
FAIT a€” Controle avant extraction du payload, apres creation de fenetre. JOURNAL entree Â« licence Â».
FAIT a€” Signature reverifiee avant avance de Seen. JOURNAL entree Â« licence Â».
FAIT a€” lic_bind reverifie la signature avant liaison. JOURNAL entree Â« A3 termine Â».
FAIT a€” Signature invalide, code 8. docs/INSTALLATION_CLIENT.md:52.
FAIT a€” Echec crypto, code 9. docs/INSTALLATION_CLIENT.md:53.
FAIT a€” private.p8 ne sort jamais, hors colis. docs/PROCEDURE_LICENCES.md:7, INSTALLER.ps1:34.
FAIT a€” public.ec et q.hex non secrets, usage interne. docs/PROCEDURE_LICENCES.md:10.
DECISION 2026-11-23 a€” private.p8 reste suivi dans le depot prive unique. JOURNAL entree Â« licence Â».
DECISION 2026-11-23 a€” kPub compile dans licence.c. docs/PROCEDURE_LICENCES.md:12.
## Role de private.p8
Decrit, jamais reproduit. 165 octets, cle privee de signature.
Qui l a peut emettre des jetons valides sans le producteur.
Sauvegarde hors machine declaree obligatoire. docs/PROCEDURE_LICENCES.md:7-8.

## Contradiction
Aucune. Document et journal concordent sur l algorithme et l ordre du controle.

## Donnees lues ou ecrites
Lit : blob public ECS1 compile, champ signature. Ecrit : rien.

## Reglages
Aucun a l execution. Couple fige a la compilation.

## Dependances
BCrypt. Tableau kPub dans licence.c.

## Points de rupture
Regenerer la paire impose de reecrire kPub, rebuilder, redistribuer. docs/PROCEDURE_LICENCES.md:12-13.
Perte de private.p8, plus aucune emission. docs/RISQUES.md:16 (R10).
Aucune sauvegarde decrite. docs/RISQUES.md:18 (R12).

## Inconnus
Nom de la fonction de verification dans licence.c.
Forme du blob ECS1 attendue.

## Sources
docs/PROCEDURE_LICENCES.md:7-13.
JOURNAL_AGENT.txt entrees Â« licence Â», Â« A3 termine Â».
docs/INSTALLATION_CLIENT.md:52-53. docs/RISQUES.md:16, 18.
