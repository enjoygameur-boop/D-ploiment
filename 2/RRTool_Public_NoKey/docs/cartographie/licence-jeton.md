# Jeton de licence

## But
Encoder machine, duree et serie dans un fichier texte signe.

## Ou ca vit
- docs/PROCEDURE_LICENCES.md:17-27
- JOURNAL_AGENT.txt entree Â« licence Â»
- 2_src_port/licence.c, non lu
- _licence/keygen.ps1, non lu

## Comment ca marche
FAIT a€” base64 sur 105 octets. JOURNAL entree Â« licence Â».
FAIT a€” Champs : magie RRL1, version, empreinte tronquee a 16, emission, expiration, serie, signature 64. JOURNAL entree Â« licence Â».
FAIT a€” Emission par keygen.ps1 avec -Fingerprint, -Days, -Serial. docs/PROCEDURE_LICENCES.md:19.
FAIT a€” -Days vaut 30 par defaut. -Serial unique et croissant. docs/PROCEDURE_LICENCES.md:27.
FAIT a€” Renommage en licence.dat avant envoi. docs/PROCEDURE_LICENCES.md:21.
FAIT a€” Jeton tronque refuse, code 3. JOURNAL entree Â« Codes de refus complets Â».
DECISION 2026-11-23 a€” Vente en joker ("FF"*16). docs/DEFAUTS.md:10.

## Contradiction
docs/PROCEDURE_LICENCES.md:24-25 decrit encore la variante liee d avance.
docs/DEFAUTS.md:10 classe le flux sans objet. Les deux cohabitent.

## Donnees lues ou ecrites
Ecrit : sortie du keygen. Lit : empreinte, serie, jours.

## Reglages
-Fingerprint, 32 hexadecimaux. -Days. -Serial.

## Dependances
_licence/keygen.ps1, _licence/private.p8.

## Points de rupture
Structure modifiee, lecture cassee.
Empreinte liee au MachineGuid, reinstallation Windows invalide le jeton (D04).
Jeton joker jamais converti (D13).
Aucune revocation (D11).

## Inconnus
Position des champs dans les 105 octets.
Encodage de la version et de la serie.

## Sources
docs/PROCEDURE_LICENCES.md:17-27.
JOURNAL_AGENT.txt entrees Â« licence Â», Â« Codes de refus complets Â».
docs/DEFAUTS.md:10-11, 18, 20.