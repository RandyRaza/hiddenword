# TP2: Programme qui résout le jeu "Mot caché"

## Description

Le projet mot_cache.c consiste à créer un programme en C qui résout le jeu "mot caché". 

Projet réalisé dans le cadre du cours Construction et maintenance de logiciels. Sigle: INF3135. Enseignant: Serge Dogny.  Université du Quebec à Montréal.

## Auteur

Randy Razafindrabe (RAZR11308805)

## Fonctionnement

Un fichier texte est passé comme argument sur stdin, le programme parcours la liste de mots qui se trouve dans le fichier et les recherche dans la grille de lettres.
Une fois que tous les mots sont trouvés, le programme récupère les dernières lettres de la grille qui n'ont pas été utilées et forme le mot caché qui est affiché sur la console.


Lorsqu'il est lancé sans argument, le programme affiche un message d'erreur.

Voici quelques commandes pour utiliser le projet:
  * La commande `make` crée l'exécutable `mot_cache` s'il y a eu une modification du fichier `mot_cache.c` en le compilant selon le standard C11, avec lesoptions `-Wall` et `-Wextra` lors de la compilation.
  * La commande `make test` recompile l'exécutable si nécessaire, puis lance la suite de tests contenue dans le fichier `check.bats`.
  * La commande `make html` transforme les fichiers `README.md` en HTML.
  * La commande `make clean` supprime les fichiers inutiles ou générés (`.o`,`.html`, etc.).

Voici un exemple de commandes pour exécuter le programme:
  ```./mot_cache exemples/mandoline.txt /mot_cache exemples/venise.txt /mot_cache make test```

## Tests

Pour lancer les tests, il suffit de lancer la commande `make test`, le fichier check.bats se lancera automatiquement: 9 tests, 0 failures.

## Dépendances

Dépendances utilisées:
  * `GCC` pour la compilation 
  * `Bats` pour les tests.
  * `<stdio.h>`
  * `<string.h>`
  * `<stdlib.h>`
  * `<unistd.h>`
  * `<ctype.h>`


