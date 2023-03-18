#ifndef MOT_CACHE_H
#define MOT_CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define TAILLE_GRILLE_MAX 12
#define TAILLE_MOT_MAX 13
#define MAX_WORD_NUM 100

/**
 * Lit un fichier de grille de mots et de liste de mots à chercher.
 * 
 * @param nom_fichier Le nom du fichier à lire.
 * @param grille La grille de mots lue depuis le fichier sera stockée ici.
 * @param mots La liste de mots à chercher lue depuis le fichier sera stockée ici.
 * @return Le nombre de mots dans la liste.
 */
int lire_fichier(char *nom_fichier, char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char mots[TAILLE_MOT_MAX][TAILLE_MOT_MAX]);

/**
 * Cherche les mots de la liste dans la grille de mots et affiche les lettres restantes.
 * 
 * @param grille La grille de mots dans laquelle chercher.
 * @param mots La liste de mots à chercher.
 * @param num_mots Le nombre de mots dans la liste.
 */
void chercher_mots(char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char mots[TAILLE_MOT_MAX][TAILLE_MOT_MAX], int num_mots);

/**
 * Construit une chaîne de caractères contenant toutes les lettres restantes de la grille de mots,
 * c'est-à-dire les lettres qui ne sont pas utilisées pour former les mots de la liste.
 * Les lettres restantes sont stockées dans le tableau lettres_restantes.
 * @param grille Le tableau de la grille de mots.
 * @param utilisees Le tableau booléen qui indique quelles lettres ont été utilisées pour former les mots de la liste.
 * @param lettres_restantes Le tableau de caractères qui va contenir les lettres restantes.
 */
void construire_mot_cache(char grille[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], bool utilisees[TAILLE_GRILLE_MAX][TAILLE_GRILLE_MAX], char lettres_restantes[TAILLE_GRILLE_MAX * TAILLE_GRILLE_MAX]);

/**
 * Vérifie le nombre d'arguments passés en ligne de commande.
 * S'il n'y a pas assez d'arguments, affiche un message d'erreur et quitte le programme.
 * @param argc Le nombre d'arguments passés en ligne de commande.
 */
void verifier_arguments(int argc);

#endif /* MOT_CACHE_H */
