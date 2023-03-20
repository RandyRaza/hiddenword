#!/usr/bin/env bats

# Compiler et exécuter les tests avec : bats tests.bats

@test "Vérifier l'exécution sans erreur" {
  run ./mot_cache exemples/mandoline.txt
  [ "$status" -eq 0 ]
}

@test "Vérifier l'erreur en cas de fichier non existant" {
  run ./mot_cache non_existant.txt
  [ "$status" -eq 1 ]
  echo "${lines[@]}" | grep -q "Erreur: impossible d'ouvrir le fichier non_existant.txt"
}

@test "Vérifier l'erreur en cas de grille invalide" {
  run ./mot_cache exemples/grille.txt
  [ "$status" -ne 0 ]
  echo "${lines[@]}" | grep -q "Erreur: grille de mots invalide, ne doit contenir que des lettres majuscules."
}

@test "Vérifier la présence du mot mystère MANDOLINE" {
  run ./mot_cache exemples/mandoline.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}" | grep -q "MANDOLINE"
}

@test "Vérifier la présence du mot mystère CALISSE" {
  run ./mot_cache exemples/calisse.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}" | grep -q "CALISSE"
}

@test "Vérifier la présence du mot mystère PARESSEUX" {
  run ./mot_cache exemples/paresseux.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}" | grep -q "PARESSEUX"
}

@test "Vérifier la présence du mot mystère VENISE" {
  run ./mot_cache exemples/venise.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}" | grep -q "VENISE"
}

@test "Vérifier la présence du mot mystère HYPOGLYCEMIQUE" {
  run ./mot_cache exemples/hypoglycemique.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}" | grep -q "HYPOGLYCEMIQUE"
}

@test "Vérifier l'erreur en cas de grille de mots invalide" {
  run ./mot_cache exemples/grille_mauvais_carac.txt
  [ "$status" -eq 1 ]
  echo "${lines[@]}" | grep -q "Erreur: grille de mots invalide, ne doit contenir que des lettres majuscules."
}
