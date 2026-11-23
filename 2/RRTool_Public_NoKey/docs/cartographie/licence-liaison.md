# Liaison de la licence a la machine

## But
Empecher qu un jeton lie serve sur une autre machine, en consommant une place unique par empreinte.

## Ou ca vit
- JOURNAL_AGENT.txt entrees Â« A3 termine Â» et Â« D01 attenue Â».
- docs/DEFAUTS.md:8 (D01), 19 (D12), 20 (D13).
- 2_src_port/licence.c, non lu.

## Comment ca marche
FAIT a€” lic_bind re-verifie la signature, refuse si le jeton est deja lie ailleurs, lit bind.dat. JOURNAL entree Â« A3 termine Â».
FAIT a€” Ecriture atomique : bind.tmp puis MoveFileEx. JOURNAL entree Â« A3 termine Â».
FAIT a€” Quota ramene de 3 a 1 sur decision utilisateur, un seul poste, support assume. JOURNAL entree Â« A3 termine Â».
FAIT a€” Quota plein remonte en code 10. JOURNAL entree Â« A3 termine Â».
FAIT a€” Empreinte conservee dans bind.dat et sous HKLM\SOFTWARE\Dreww valeur Bind. JOURNAL entree Â« D01 attenue Â».
FAIT a€” Lecture en union, ecriture sur les deux supports des qu il y a touche. JOURNAL entree Â« D01 attenue Â».
FAIT a€” Suppression d un seul support, l autre recree la valeur. JOURNAL entree Â« D01 attenue Â».
FAIT a€” Empreinte etrangere refusee en 10, jeton lie ailleurs refuse avant liaison, bind.dat intact. JOURNAL entree Â« A3 termine Â».
DECISION 2026-11-23 a€” Quota de 1, support assume. JOURNAL entree Â« A3 termine Â».
## Contradiction
JOURNAL entree Â« A3 termine Â» annonce le quota ramene a 1 ; docs/DEFAUTS.md:19 (D12) constate que les codes 5 et 10 portent le meme texte, donc l acheteur ne distingue pas un fichier d une autre machine d une place deja prise.

## Donnees lues ou ecrites
Lit et ecrit : bind.dat, valeur Bind sous HKLM\SOFTWARE\Dreww.
Ecrit : bind.tmp en passage.

## Reglages
Quota fixe a 1. Aucun reglage d execution.

## Dependances
licence.c, HKLM, MoveFileEx, elevation par manifeste.

## Points de rupture
D01 attenue seulement : effacer les deux supports libere la place. docs/DEFAUTS.md:8.
bind.dat n est pas signe. docs/DEFAUTS.md:8.
Le code 10 ne dit pas si la place est prise par soi-meme ou par un autre. docs/DEFAUTS.md:19.
Reinstallation de Windows, empreinte neuve, jeton a refaire. docs/DEFAUTS.md:11.
Le jeton joker n est jamais converti, seule la place est consommee. docs/DEFAUTS.md:20.

## Inconnus
Format de bind.dat. Emplacement de l appel a lic_bind dans aio_launcher.c.
Sort de bind.tmp si l ecriture echoue en cours de route.

## Sources
JOURNAL_AGENT.txt entrees Â« A3 termine Â», Â« D01 attenue Â». docs/DEFAUTS.md:8, 11, 19, 20.
