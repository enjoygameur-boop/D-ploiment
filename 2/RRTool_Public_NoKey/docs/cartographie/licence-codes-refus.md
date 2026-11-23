# Codes de refus de licence

## But

Nommer chaque cause de refus par un entier, pour que l acheteur transmette un code au support sans transmettre le fichier.

## Ou ca vit

- docs/INSTALLATION_CLIENT.md:42-56 a€” table publique des codes.
- JOURNAL_AGENT.txt entree Â« licence Â» a€” liste interne 1 a 10.
- JOURNAL_AGENT.txt entree Â« Codes de refus complets Â» a€” preuve reelle de 2, 3 et 9.
- 2_src_port/licence.c a€” emission des codes, non lue directement, voir MANQUES.md.

## Comment ca marche

FAIT a€” Le refus affiche un code et l empreinte de la machine. docs/INSTALLATION_CLIENT.md:44.
FAIT a€” Le support recoit le code et l empreinte, pas licence.dat. docs/INSTALLATION_CLIENT.md:56.
FAIT a€” Codes documentes cote client : 1, 2, 3, 5, 6, 7, 8, 9, 10. docs/INSTALLATION_CLIENT.md:46-54.
FAIT a€” Codes documentes cote interne : 1 introuvable, 2 illisible, 3 mal forme, 4 inconnu, 5 autre machine, 6 expiree, 7 horloge, 8 signature, 9 crypto. JOURNAL entree Â« licence Â».
FAIT a€” Code 10 : quota de liaison plein. JOURNAL entree Â« A3 termine Â».
FAIT a€” Le controle est pose avant extraction du payload, apres creation de fenetre. JOURNAL entree Â« licence Â».
DECISION 2026-11-23 a€” Les dix codes sont prouves en reel. JOURNAL entree Â« Codes de refus complets Â».

## Contradiction

Le code 4 existe dans la liste interne et manque dans la table publique. docs/INSTALLATION_CLIENT.md:46-54 saute de 3 a 5. Un acheteur qui recoit 4 n a pas de ligne de correspondance.
Les deux sources sont conservees. La liste interne est la plus complete, la table publique est la plus recente cote livrable.

## Donnees lues ou ecrites

- Lecture : licence.dat, MachineGuid, valeurs registre Seen et Bind.
- Ecriture : message de refus en fenetre, avec code et empreinte.

## Reglages

Aucun reglage. Les codes sont fixes.

## Dependances

- licence.c, licence.h a€” production des codes.
- aio_launcher.c a€” affichage et arret.
- kMsg a€” table de messages. JOURNAL entree Â« A3 termine Â».

## Points de rupture

- Toute retouche de licence.c decale la correspondance code/texte. La table publique est en dur dans le document client.
- Le code 10 depend du quota de liaison, ramene de 3 a 1. JOURNAL entree Â« A3 termine Â».
- Le texte des codes 5 et 10 est identique cote produit. docs/DEFAUTS.md:19 (D12, ouvert).

## Inconnus

- Emplacement exact de chaque retour de code dans licence.c. INCONNU, fichier non lu.
- Comportement du code 4 : jamais provoque. JOURNAL entree Â« licence Â».

## Sources

docs/INSTALLATION_CLIENT.md:42-56 ; JOURNAL_AGENT.txt entrees Â« licence Â», Â« A3 termine Â», Â« Codes de refus complets Â» ; docs/DEFAUTS.md:19.
