# Synthese des journaux et notes

Une ligne par entree, datee, avec ce qui reste vrai et ce qui est perime.

## JOURNAL_AGENT.txt
2026-11-21 FINAL, fast_scan : chaine et valeur 0.0001f, restauration, decocher avant fermeture sinon crash. VRAI, repris par fast-scan.md. La ligne est ecrite deux fois de suite.
2026-11-22, flics jamais vises : rr_relationship_allowed passe en inclusion, geometrie 0.95 m, exemption vehicule, aa_target_police a 1. VRAI, verifie en jeu. Seuil et exemption restent a confirmer.
2026-11-23, embleme AIO : ressource 105, 32 bpp seulement, code mort de la branche bitmap. VRAI. Quatre builds overlay de tailles differentes cites.
2026-11-23, licence : jeton RRL1, ECDSA P-256, anti-recul Seen 24 h, codes 1 a 9. VRAI. Codes 2 et 9 alors non provoques.
2026-11-23, A3 : lic_bind, quota 3 puis 1, code 10, messages alignes. VRAI. Le quota a ete ramene a 1 par decision.
2026-11-23, codes complets : 2, 3 et 9 prouves. VRAI, les dix codes sont prouves.
2026-11-23, livrables : document client, scripts setup, keygen a 30 jours, README_ARCHIVE, SINGLE_BUILD obsolete. VRAI sauf setup/2_creer_dossier.ps1, retire le meme jour.
2026-11-23, D01 attenue : bind.dat plus valeur Bind, union, recreation mutuelle. VRAI. Effacer les deux libere la place.
2026-11-23, test en jeu : refus de mappage nomme, hyperviseur coupe, overlay present. VRAI. L AIO se ferme et l overlay se masque, Get-Process ne les voit pas.
2026-11-23, restants : INSTALLER.ps1 non teste, trois defauts connus. PERIME, l installateur a ete durci et teste ensuite.
2026-11-23, installateur durci : chemin par MyInvocation, liste blanche, -NoReboot. VRAI. Le raccourci vise START.bat dans cette entree.
2026-11-23, installation validee : raccourci corrige vers FFLoader.exe. VRAI, INSTALLER.ps1:77 le confirme.
2026-11-23, document ramene a la voie installateur. VRAI.
2026-11-23, etat des lieux classe. VRAI.
2026-11-23, D15 classe sans suite. VRAI, pas de desinstalleur.
2026-11-23, rangement de la racine. VRAI, _scratch cree.
2026-11-23, notes obsoletes deplacees. VRAI, README encore faux a ce moment.
2026-11-23, README recadre, D10 ferme. VRAI.
2026-11-23, INSTALLER.cmd. VRAI.
2026-11-23, D05 ferme. VRAI. docs/DEFAUTS.md:12 le porte encore ouvert.
2026-11-23, D02 ferme, D03 classe. VRAI.
2026-11-23, setup/2_creer_dossier.ps1 retire. VRAI, absent du depot.
2026-11-23, manuel utilisateur. VRAI, hors docs.

## _scratch

HANDOFF_suivant.txt : protocole de patch, chaine canonique de feature, architecture du payload, fragilites, protocole de save et de build. VRAI et encore structurant. La section 11 decrit une save zip qui n existe plus a la racine.
HANDOFF_aim_suivant.txt : chaine knocked, pieges d offset, inventaire des fichiers. VRAI. La section 6 signale que p->dead n est jamais assigne.
MAINTENANCE_fast_scan.txt : procedure complete de refection. VRAI.
SINGLE_BUILD.md : marque partiellement obsolete en tete, chemins et payload faux. PERIME.
README.txt de _scratch : brouillons non citables. VRAI.

## docs

DEFAUTS.md : quinze lignes. D02, D10, D14 fermes, D03 classe, D01 attenue, D04, D06, D09, D11, D13 assumes, D05, D07, D08, D12, D15 ouverts. La ligne D05 est perimee, le journal la ferme.
RISQUES.md : quinze lignes, parades a jour au 2026-11-23.
INSTALLATION_CLIENT.md : document livre, a jour. La table des codes omet le 4.
PROCEDURE_LICENCES.md : document interne, a jour. Decrit encore la variante liee d avance.
