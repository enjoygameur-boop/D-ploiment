# Dreww - procedure d emission des licences

Document interne. Jamais livre a un acheteur.

## Ce qui ne sort jamais

`_licence\private.p8` uniquement. Qui l a peut signer des jetons valides sans toi.
Sauvegarde hors machine obligatoire, des maintenant.

`public.ec` et `q.hex` ne sont pas secrets, mais ne servent qu en interne.

Regenerer la paire casse tout: `kPub` est compile dans `licence.c`. Il faut reecrire
le tableau, rebuilder, redistribuer. Les jetons deja emis deviennent invalides.

## Emission

Depuis C:\Users\ABC\Desktop\Cheats\2\RRTool_Public_NoKey:

    powershell -NoProfile -ExecutionPolicy Bypass -File "_licence\keygen.ps1" -Fingerprint ("FF"*16) -Days 30 -Serial 1001 -Out "_licence\1001.txt"

Renommer le resultat en licence.dat, l envoyer avec le dossier.
Noter la sortie console: serie et date d expiration.

Variante liee d avance: remplacer le joker par l empreinte 32 caracteres hexadecimaux
de l acheteur, qu il lit dans la fenetre de refus ou dans le registre.

`-Serial` doit etre unique et croissant. `-Days` vaut 30 par defaut.

## Journal des ventes

`_licence\VENTES.txt`, une ligne par vente, jamais modifiee apres coup:

    SERIE | DATE | PSEUDO | MONTANT | EMPREINTE | NOTE

## Support

Remplacement sur ticket: nouvel `-Serial`, nouvelle expiration, joker ou empreinte
neuve. Jamais reutiliser une serie.

## Verification apres sauvegarde de la cle

    powershell -NoProfile -ExecutionPolicy Bypass -File "_licence\keygen.ps1" -Days 1 -Serial 1 -Out "$env:TEMP\t.txt"

Un jeton doit sortir. Sinon la cle restauree est mauvaise.
