# Alerte d expiration

## But
Prevenir l acheteur avant l echeance au lieu d un refus brutal au dernier jour.

## Ou ca vit
- JOURNAL_AGENT.txt entree Â« D05 ferme: alerte d expiration Â».
- 2_src_port/licence.h et licence.c, lic_days_left, non lus.
- 2_src_port/aio_launcher.c, appel, non lu.

## Comment ca marche
FAIT a€” lic_days_left relit le jeton, verifie la signature et rend les jours restants. JOURNAL entree Â« D05 ferme Â».
FAIT a€” Sous 7 jours, le lanceur journalise Â« licence: OK, expire dans N jour(s) Â». JOURNAL entree Â« D05 ferme Â».
FAIT a€” Arrondi tronque corrige en arrondi superieur apres test a 3 jours. JOURNAL entree Â« D05 ferme Â».
FAIT a€” Deux builds propres, driver mappe, overlay fonctionnel apres la pose. JOURNAL entree Â« D05 ferme Â».
DECISION 2026-11-23 a€” D05 ferme par un journal, sans avertissement d interface. JOURNAL entree Â« D05 ferme Â».
## Contradiction
docs/DEFAUTS.md:12 porte encore D05 Â« ouvert Â» avec Â« refus brutal au 31e jour, sans preavis Â». Le journal du meme jour le ferme. La ligne du registre n a pas suivi. Sujet traite, la trace textuelle est perimee.

## Donnees lues ou ecrites
Lit : jeton, signature. Ecrit : une ligne de journal.

## Reglages
Seuil fixe de 7 jours.

## Dependances
licence.h, licence.c, aio_launcher.c, BCrypt.

## Points de rupture
Un jeton deja expire fait echouer lic_days_left comme la verification. Deduit du controle de signature.
Aucun avertissement visible pour l acheteur qui ne lit pas le journal. docs/DEFAUTS.md:12.

## Inconnus
Emplacement de l appel dans aio_launcher.c.
Un jeton joker donne-t-il un compte de jours exploitable.

## Sources
JOURNAL_AGENT.txt entree Â« D05 ferme Â». docs/DEFAUTS.md:12.
