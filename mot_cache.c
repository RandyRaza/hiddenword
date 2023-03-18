#include "mot_cache.h"


int lire_fichier(char *nom_fichier, char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char mots[TAILLE_MOT_MAX][TAILLE_MOT_MAX])
{
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL)
    {
        printf("Erreur: impossible d'ouvrir le fichier %s.\n", nom_fichier);
        exit(1);
    }

    int num_mots = 0;
    char word[TAILLE_MOT_MAX];

    for (int rangee = 0; rangee < TAILLE_GRILLE_MAX; rangee++)
    {
        if (fgets(grille[rangee], TAILLE_GRILLE_MAX + 2, fichier) == NULL)
        {
            printf("Erreur: fichier de grille de mots invalide.\n");
            exit(1);
        }

        grille[rangee][strcspn(grille[rangee], "\n")] = '\0';
        for (int colonne = 0; colonne < TAILLE_GRILLE_MAX; colonne++)
        {
            if (grille[rangee][colonne] < 'A' || grille[rangee][colonne] > 'Z')
            {
                printf("Erreur: grille de mots invalide, ne doit contenir que des lettres majuscules.\n");
                exit(1);
            }
        }
    }

    while (fscanf(fichier, "%s", word) == 1)
    {
        if (strlen(word) > TAILLE_MOT_MAX - 1)
        {
            printf("Erreur: mot invalide.\n");
            exit(1);
        }

        for (int i = 0; i < (int)strlen(word); i++)
        {
            if (word[i] < 'A' || word[i] > 'Z')
            {
                printf("Erreur: mot invalide.\n");
                exit(1);
            }
        }
        strncpy(mots[num_mots], word, TAILLE_MOT_MAX );
        num_mots++;
    }

    fclose(fichier);
    return num_mots;
}

void construire_mot_cache(char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], bool utilisees[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char lettres_non_utilisees[TAILLE_GRILLE_MAX * TAILLE_GRILLE_MAX])
{
    int index = 0;
    for (int rangee = 0; rangee < TAILLE_GRILLE_MAX; rangee++)
    {
        for (int col = 0; col < TAILLE_GRILLE_MAX; col++)
        {
            if (!utilisees[rangee][col])
            {
                lettres_non_utilisees[index++] = grille[rangee][col];
            }
        }
    }
    lettres_non_utilisees[index] = '\0';
}

void chercher_mots(char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char words[TAILLE_MOT_MAX][TAILLE_MOT_MAX], int num_mots)
{
    char lettres_non_utilisees[TAILLE_GRILLE_MAX * TAILLE_GRILLE_MAX];
    bool utilisees[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX] = {false};

    for (int i = 0; i < num_mots; i++)
    {
        char *word = words[i];
        int word_len = strlen(word);

        for (int rangee = 0; rangee < TAILLE_GRILLE_MAX; rangee++)
        {
            for (int col = 0; col < TAILLE_GRILLE_MAX; col++)
            {

                if (grille[rangee][col] == word[0])
                {
                    int j;
                    for (j = 1; j < word_len; j++)
                    {
                        if (col + j >= TAILLE_GRILLE_MAX || grille[rangee][col + j] != word[j])
                        {
                            break;
                        }
                    }
                    if (j == word_len)
                    {
                        for (j = 0; j < word_len; j++)
                        {
                            utilisees[rangee][col + j] = true;
                        }
                        continue;
                    }
                    for (j = 1; j < word_len; j++)
                    {
                        if (col - j < 0 || grille[rangee][col - j] != word[j])
                        {
                            break;
                        }
                    }
                    if (j == word_len)
                    {
                        for (j = 0; j < word_len; j++)
                        {
                            utilisees[rangee][col - j] = true;
                        }
                        continue;
                    }

                    for (j = 1; j < word_len; j++)
                    {
                        if (rangee + j >= TAILLE_GRILLE_MAX || grille[rangee + j][col] != word[j])
                        {
                            break;
                        }
                    }
                    if (j == word_len)
                    {
                        for (j = 0; j < word_len; j++)
                        {
                            utilisees[rangee + j][col] = true;
                        }
                        continue;
                    }
                    for (j = 1; j < word_len; j++)
                    {
                        if (rangee - j < 0 || grille[rangee - j][col] != word[j])
                        {
                            break;
                        }
                    }
                    if (j == word_len)
                    {
                        for (j = 0; j < word_len; j++)
                        {
                            utilisees[rangee - j][col] = true;
                        }
                        continue;
                    }
                }
            }
        }
    }
    construire_mot_cache(grille, utilisees, lettres_non_utilisees);
    printf("Mot caché : %s\n", lettres_non_utilisees);
}

void verifier_arguments(int argc) {
    if (argc != 2) {
        fprintf(stderr, "Erreur : Le programme doit recevoir un et un seul argument.\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {

    verifier_arguments(argc);

    char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX];
    char words[MAX_WORD_NUM][TAILLE_MOT_MAX];
    int num_mots = lire_fichier(argv[1], grille, words);

    chercher_mots(grille, words, num_mots);

    return 0;
}


