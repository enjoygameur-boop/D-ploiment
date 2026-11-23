# Auto-test hors ligne

## But
Verifier sans jeu ni pilote des contrats internes : configuration, dispositions IL2CPP, projection, analyse de chaines.

## Ou ca vit
- selftest.log:1-25, sortie de reference
- BUILD.md section Check the overlay offline
- rr_esp.c, run_selftest(), non lu

## Comment ca marche
FAIT a€” Mode appele par --selftest --nohide --no-pause. BUILD.md section Check the overlay offline.
FAIT a€” Code de sortie zero et SELFTEST OK signifient reussite. Meme section.
FAIT a€” Vingt-deux cas PASS, zero echec dans la sortie de reference. selftest.log:2-23, 25.FAIT a€” Les cas couvrent configuration, filtres de rarete, import herite, en-tete IL2CPP a 16 octets, static_fields a 0xB8, chaine, dictionnaire, trois offsets de modele, quatre cas de projection, chaine a deux symboles. selftest.log:2-23.
FAIT a€” Ne verifie ni jeu courant, ni pilote, ni rig, ni serveur. BUILD.md section Check the overlay offline.
FAIT a€” Tous les modes partagent le manifeste et demandent l elevation. Meme section.
FAIT a€” Le journal s ecrit dans selftest.log. selftest.log:1.

## Donnees lues ou ecrites
Ecrit : selftest.log. Lit : configuration par defaut, constantes de disposition.

## Reglages
--nohide supprime la demande de visibilite. --no-pause evite l attente.

## Dependances
Aucune dependance externe.

## Points de rupture
Un offset faux fait echouer un cas nomme, un offset faux non couvert passe. selftest.log:8-15 ne couvre que six champs.
Le journal est ecrase a chaque execution, un PASS ancien ne prouve rien.
selftest.log du depot date de l etat initial. JOURNAL entree Rangement de la racine.

## Inconnus
Liste reelle des assertions dans run_selftest().
Le log versionne vient-il de la build courante.

## Sources
selftest.log:1-25. BUILD.md section Check the overlay offline. JOURNAL entree Rangement de la racine.
