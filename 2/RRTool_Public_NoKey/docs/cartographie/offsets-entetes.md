# En-tetes d offsets

## But
Fournir les champs managed et leurs offsets au code de lecture.
## Ou ca vit
- 2_src_port/robrun_offsets.h, 4827 octets
- 2_src_port/robrun_sdk_offsets.h, 10249 octets
- robrun_sdk_offsets.h:40, 43, exemples

## Comment ca marche
FAIT a€” Les deux en-tetes sont inclus, un build normal ne demande ni Python ni fichier de jeu. BUILD.md section Understand the offset inputs.
FAIT a€” Les hashes et references de source identifient les instantanes d origine. Meme section.
FAIT a€” RR_OFF_CHAR_STATE 0x1E0, RR_OFF_CHAR_KNOCK_MODEL 0x30 sur le modele d etat, RR_OFF_KNOCK_PHASE 0x18, RR_OFF_REF_VALUE 0x18, RR_OFF_DESC_NAME 0x10, RR_OFF_ENUM_INDEX 0x18. _scratch/HANDOFF_aim_suivant.txt Â§3.
FAIT a€” RR_OFF_CHAR_ISDEAD vaut 0xF0 et ne sert a rien, la valeur juste est 0x10 sur le modele d etat. Meme fichier Â§6.
FAIT a€” RR_OFF_KNOCK_FORWARD et RR_OFF_KNOCK_PHASE valent tous deux 0x18, RR_OFF_KNOCK_ENDTS et RR_OFF_KNOCKDOWN_ENDTS tous deux 0x10. Meme section.
FAIT a€” RR_OFF_PHASE_KNOCKEDOUT 0x08 est declare en blob statique non prouve. robrun_sdk_offsets.h:43.
FAIT a€” Six champs de disposition sont verifies par le selftest. selftest.log:8-15.
FAIT a€” Les en-tetes ne valident pas les structures Unity natives, les charges generiques, les corps de methodes ni les identites de tas. README section Memory and validation lessons.

## Donnees lues ou ecrites
Aucune. En-tetes compiles.

## Reglages
Aucun.

## Dependances
robrun_offsets.h, robrun_sdk_offsets.h, generation.

## Points de rupture
Patch du jeu, offsets morts, lecture plausible mais fausse.
Un offset duplique employe sur le mauvais modele donne un verdict faux. _scratch/HANDOFF_aim_suivant.txt Â§6.

## Inconnus
Correspondance entre les deux en-tetes et les builds de jeu.

## Sources
BUILD.md section Understand the offset inputs. robrun_sdk_offsets.h:40, 43. selftest.log:8-15. README section Memory and validation lessons. _scratch/HANDOFF_aim_suivant.txt Â§3, Â§6.
