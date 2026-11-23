# Fast scan des contenants

## But
Reveler instantanement le contenu des contenants en ecrasant un flottant global, par patch de cinq sites de code.
## Ou ca vit
- 2_src_port/rr_exp.c, 46038 octets
- _scratch/MAINTENANCE_fast_scan.txt, integral
- JOURNAL_AGENT.txt entree 2026-11-21 FINAL

## Comment ca marche
FAIT a€” Chaine sans balayage : BattleEntitiesUpdater + 0x68, BattleScreenContent + 0x540, InventoryRevealViewDescriptions + 0x58, flottant ecrase a 0.0001f. _scratch/MAINTENANCE_fast_scan.txt A1.
FAIT a€” Source de l updater : g_views_updater, expose par rr_game_views_updater(). Meme fichier A2.
FAIT a€” Cinq sites RVA avec octets d origine en dur : get 0x843A30, set 0x900920, dly1 0xA5D5C4, dly2 0xA5E722, dly3 0xA5E754. Meme fichier A3.
FAIT a€” get et set sont inlines, zero appel dans le binaire, les trois dly seuls ne suffisent pas. Meme fichier A3.
FAIT a€” Restauration des valeurs et des octets au decochage. Meme fichier A4.
FAIT a€” Decocher avant de fermer le jeu, sinon crash. JOURNAL entree 2026-11-21.
FAIT a€” Journal rr_exp.log dans %LOCALAPPDATA%\Temp. _scratch/MAINTENANCE_fast_scan.txt E5.
FAIT a€” EOS ferme Cheat Engine et bloque ses lectures, le driver passe. Meme fichier E2.

## Donnees lues ou ecrites
Ecrit : flottant global, octets de code, rr_exp.log.

## Reglages
Case Fast scan. Journal attendu : module, get ok, set ok, dly1 a 3 ok, INST, zeroed. Meme fichier D3.

## Dependances
rr_exp.c, rr_game_views_updater, offsets EXP_OFF et EXP_DLY*_RVA.

## Points de rupture
Patch du jeu, chaine ou RVA mortes, rien ne s ouvre.
Fermeture du jeu sans decocher, crash. JOURNAL entree 2026-11-21.
Deux drivers charges se genent. Meme fichier E6.

## Inconnus
Validite des RVA sur la build courante. Effet du zeroed sur les contenants deja ouverts.

## Sources
_scratch/MAINTENANCE_fast_scan.txt integral. JOURNAL_AGENT.txt entree 2026-11-21 FINAL.

## Ancres de ligne
- rr_exp.c:963, avertissement C4101 sur rr_exp.c, docs/DEFAUTS.md:15
- _scratch/MAINTENANCE_fast_scan.txt A1 a A4, chaine et sites RVA, sans numero de ligne
- rr_game.c, g_views_updater et rr_game_views_updater, sans numero de ligne
