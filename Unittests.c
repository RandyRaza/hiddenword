#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>
#include "mot_cache.h"

#define TAILLE_GRILLE_MAX 12
#define TAILLE_MOT_MAX 13


void test_ouverture_fichier()
{
    char* nom_fichier = "test.txt";
    FILE *fichier = fopen(nom_fichier, "r");
    CU_ASSERT_TRUE(fichier != NULL);
    fclose(fichier);
}


void test_lire_fichier(void)
{
    char nom_fichier[] = "grille_mots.txt";
    char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX];
    char mots[TAILLE_MOT_MAX][TAILLE_MOT_MAX];

    // Test avec un fichier valide
    int num_mots = lire_fichier(nom_fichier, grille, mots);
    CU_ASSERT(num_mots == 5);

    // Vérification du contenu de la grille
    char grille_attendue[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {
            "AMETTENIRALC",
            "CGUITAREXIOV",
            "CASOOEMATMAT",
            "OMARJDCBHNBE",
            "RUXGNRLUAEAN",
            "DIOUAAATRLTO",
            "ENPEBBVFPATH",
            "OOHOEMILEBEP",
            "NMONROEUDMRO",
            "LRNAYBRTOYIL",
            "OAEILLIENCEY",
            "SHEPOLOCCIPX",



    };
    for (int i = 0; i < TAILLE_GRILLE_MAX; i++) {
        CU_ASSERT_STRING_EQUAL(grille[i], grille_attendue[i]);
    }

    // Vérification du contenu des mots
    char mots_attendus[TAILLE_MOT_MAX][TAILLE_MOT_MAX] = {
            "ACCORDEON",
            "BANJO",
            "BATTERIE",
            "BOMBARDE",
            "CLARINETTE"
    };
    for (int i = 0; i < num_mots; i++) {
        CU_ASSERT_STRING_EQUAL(mots[i], mots_attendus[i]);
    }

    // Test avec un fichier inexistant
    char nom_fichier_inexistant[] = "fichier_inexistant.txt";
    CU_ASSERT_FATAL(lire_fichier(nom_fichier_inexistant, grille, mots) == -1);
}

void test_construire_mot_cache()
{
    char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {
            {'A', 'B', 'C'},
            {'D', 'E', 'F'},
            {'G', 'H', 'I'}
    };
    bool utilisees[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {
            {false, false, false},
            {false, false, false},
            {false, false, false}
    };
    char lettres_non_utilisees[TAILLE_GRILLE_MAX * TAILLE_GRILLE_MAX];

    construire_mot_cache(grille, utilisees, lettres_non_utilisees);

    // Vérifier que les lettres non utilisées sont correctes
    CU_ASSERT_STRING_EQUAL(lettres_non_utilisees, "ABCDEFGHI");

    // Vérifier que toutes les lettres ont été ajoutées une seule fois
    for (int i = 0; i < TAILLE_GRILLE_MAX * TAILLE_GRILLE_MAX; i++)
    {
        for (int j = i + 1; j < TAILLE_GRILLE_MAX * TAILLE_GRILLE_MAX; j++)
        {
            CU_ASSERT_NOT_EQUAL(lettres_non_utilisees[i], lettres_non_utilisees[j]);
        }
    }
}

void test_chercher_mots() {
    char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {
            {'S', 'E', 'A', 'U', 'N'},
            {'I', 'E', 'L', 'E', 'T'},
            {'T', 'A', 'G', 'N', 'C'},
            {'E', 'L', 'U', 'O', 'R'},
            {'A', 'M', 'M', 'A', 'T'}
    };
    char words[TAILLE_MOT_MAX][TAILLE_MOT_MAX] = {"TAG", "MAT", "SEAU", "TELE", "ROULE"};
    int num_mots = 5;

    chercher_mots(grille, words, num_mots);
    // Le résultat devrait être "NINCAM"
}


void test_verifier_arguments() {
    int argc = 1;
    CU_ASSERT_TRUE(verifier_arguments(argc) == 0);
}

int main()
{
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("test_ouverture_fichier", NULL, NULL);
    CU_add_test(suite, "test_ouverture_fichier", test_ouverture_fichier);

    CU_pSuite suite2 = CU_add_suite("Suite de tests", NULL, NULL);
    CU_add_test(suite2, "Test de la fonction lire_fichier", test_lire_fichier);

    CU_pSuite suite3 = CU_add_suite("Suite de tests pour construire_mot_cache", NULL, NULL);
    CU_add_test(suite3, "Test de la fonction construire_mot_cache", test_construire_mot_cache);

    CU_pSuite suite4 = CU_add_suite("Suite de tests pour verifier_arguments", NULL, NULL);
    CU_add_test(suite4, "Test de la fonction verifier_arguments", test_verifier_arguments);

    CU_pSuite suite5 = CU_add_suite("Suite de tests chercher_mots", NULL, NULL);
    CU_add_test(suite5, "test_chercher_mots", test_chercher_mots);



    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();

    return 0;
}

