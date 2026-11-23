# Entrees clavier

## But
Recevoir les actions de l utilisateur par plusieurs sources et les journaliser.
## Ou ca vit
- rr_esp.c:94-115, hklogf serialise, cite par sonde
- rr_esp.c:130-147, actions, citees par sonde
- rr_esp.c:190-204, anti-rebond et touche maintenue, cites par sonde
- rr_esp.c:2884, journal d initialisation, cite par sonde

## Comment ca marche
FAIT a€” Quatre sources : hotkey enregistree, crochet, entree brute, interrogation. rr_esp.c:2884 et commentaire de rr_esp.c:88-90.
FAIT a€” hklogf serialise l ecriture par section critique, les sources venant de fils differents. rr_esp.c:94-115.
FAIT a€” F1 bascule le menu, Insert l overlay, End quitte. rr_esp.c:130-147.
FAIT a€” Une touche maintenue est ignoree, un anti-rebond par age s applique. rr_esp.c:190-204.
FAIT a€” La source est journalisee pour chaque action. rr_esp.c:190-204.
FAIT a€” Une touche sans effet s inspecte dans hotkeys.log et l etat du menu. README section Interpreting failures.
FAIT a€” Le journal s ecrit a cote de l exe. _scratch/_probe_hk2.txt.

## Donnees lues ou ecrites
Ecrit : hotkeys.log. Lit : evenements clavier.

## Reglages
Touche de visee configurable. README section Controls and settings.

## Dependances
rr_esp.c, crochet clavier, entree brute.

## Points de rupture
Un filtre qui capte le clavier ailleurs, source muette.
Perte de focus, actions non delivrees.

## Inconnus
Delai exact de l anti-rebond. Ordre de priorite des sources.

## Sources
rr_esp.c:94-115, 130-147, 190-204, 2884, cites par sonde. _scratch/_probe_hk2.txt. README section Interpreting failures.
