# Manques

Ce qu aucun document ne couvre et qui bloque une reprise.

## Lecture non faite
Ces fichiers n ont pas ete lus a la source, les fiches correspondantes reposent sur des documents ou des sondes.
- 2_src_port/licence.c, licence.h
- 2_src_port/aio_launcher.c, 66567 octets
- 2_src_port/rr_esp.c, 121289 octets
- 2_src_port/rr_game.c, 265476 octets, rr_game.h
- 2_src_port/rr_aim.c, 15118 octets, rr_aim.h
- 2_src_port/rr_mem.c, rr_mem.h
- 2_src_port/rr_unity.c, rr_unity.h
- 2_src_port/rr_draw.c, rr_draw.h
- 2_src_port/rr_exp.c, 46038 octets
- 2_src_port/rr_spawn.c, rr_spawn.h
- 2_src_port/rr_chain.c, rr_chain.h
- 2_src_port/rr_classscan.c, rr_nodescan.c, rr_find.c
- 2_src_port/rr_los.c, rr_los_capture.c, rr_los_geom.c, rr_los_runtime.c et en-tetes
- 2_src_port/gpu.cpp, gpu.h
- 2_src_port/menu.html, menu_webview.cpp, wv2_cb.h, wv2_cb_impl.h
- 2_src_port/rr_pose_gate.h, rr_cham_coherence.h, rr_rig_map.h, rr_body_joints.h, rr_hiding.h, rr_world_marker_select.h, rr_rapid.h
- 2_src_port/build_port.bat, build_aio.bat, update_menu.ps1
- 3_src_driver/wm_drv.c, wm.h, build_driver.bat
- 5_src_loader/loader.cpp
- _licence/keygen.ps1
- setup/1_couper_hyperviseur.ps1
- 1_run/*.bat, RobRunAIO.ini, kd2.cfg, payload/CoreRR.cfg
- offsets/*.json

## Manques reels
- Aucun _licence/VENTES.txt livre, alors que docs/PROCEDURE_LICENCES.md:31 le declare obligatoire. Le suivi des ventes n a pas de support.
- Aucun dossier tools/ dans le depot, alors que BUILD.md decrit trois outils. Les offsets ne sont pas regenerables en l etat.
- Aucun dossier dist/, cite par le README comme sortie de distribution vide.
- Aucun flux d activation : l empreinte se lit a la main. docs/DEFAUTS.md:10.
- Aucun desinstalleur : restes sous %LOCALAPPDATA% et HKLM. docs/DEFAUTS.md:22.
- Aucun test de ressenti rapporte a la cloture. _scratch/HANDOFF_suivant.txt Â§7.
- Aucune signature de binaire. docs/DEFAUTS.md:14.
- Aucune revocation de licence. docs/DEFAUTS.md:18.
- Aucune sauvegarde de la cle privee decrite en procedure. docs/RISQUES.md:18.
- Le contrat du loader DrewwLoader.exe n est documente nulle part.
- Le mode dump n a aucune documentation.
- Les bornes et le format de la configuration ne sont pas decrits hors du schema.

## Contradictions non tranchees
- Code 4 absent de la table publique, present en interne. docs/INSTALLATION_CLIENT.md:46-54 contre JOURNAL entree licence.
- Raccourci START.bat puis DrewwLoader.exe. JOURNAL, deux entrees du meme jour.
- D05 ouvert au registre, ferme au journal.
- Trois hachages pour une meme taille dans _wl.txt.
- docs reduits a un fichier annonce, docs/branding copie quand meme.
