prog=mot_cache

@test "Fichier non existant" {
  run ./$prog non_existant.txt
  [ "$status" -eq 1 ]
  echo "${lines[@]}" | grep -q "Erreur: impossible d'ouvrir le fichier non_existant.txt"
}


@test "Test de lecture de grille de lettres invalide - grille non valide" {
  run ./$prog exemples/grille.txt
  [ "$status" -ne 0 ]
  echo "I,N,V,A,L,I,D,E,," > grille.txt
  echo "C,E,C,I,S,E,L,E," >> grille.txt
  echo "A,E,T,O,M,E,R,D" >> grille.txt
  echo "N,E,N,E,U,E,M,E," >> grille.txt
  echo "C,I,N,Q,U,A,N,T," >> grille.txt
  echo "O,S,I,E,R,E,S,T," >> grille.txt
  echo "R,E,C,E,L,E,R,A," >> grille.txt
  echo "C,E,D,E,F,E,N,E," >> grille.txt
  echo "A,I,N,S,I,M,P,L,E" >> grille.txt
  echo "S,A,M,E,D,I,A,P," >> grille.txt
  echo "E,M,A,T,A,N,T,E," >> grille.txt
  echo ",,I,N,V,A,L,I,D,E" >> grille.txt
}

@test "Grille valide" {
    run ./$prog exemples/calisse.txt
    [ "$status" -eq 0 ]
}

@test "Vérifier la présence du mot mystère MANDOLINE" {
  run ./$prog exemples/mandoline.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}"
  echo "${lines[@]}" | grep -q "MANDOLINE"
  [ "$?" -eq 0 ]
}

@test "Vérifier la présence du mot mystère CALISSE" {
  run ./$prog exemples/calisse.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}"
  echo "${lines[@]}" | grep -q "CALISSE"
  [ "$?" -eq 0 ]
}

@test "Vérifier la présence du mot mystère PARESSEUX" {
  run ./$prog exemples/paresseux.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}"
  echo "${lines[@]}" | grep -q "PARESSEUX"
  [ "$?" -eq 0 ]
}

@test "Vérifier la présence du mot mystère VENISE" {
  run ./$prog exemples/venise.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}"
  echo "${lines[@]}" | grep -q "VENISE"
  [ "$?" -eq 0 ]
}

@test "Vérifier la présence du mot mystère HYPOGLYCEMIQUE" {
  run ./$prog exemples/hypoglycemique.txt
  [ "$status" -eq 0 ]
  echo "${lines[@]}"
  echo "${lines[@]}" | grep -q "HYPOGLYCEMIQUE"
  [ "$?" -eq 0 ]
}

@test "Erreur pour une grille de mots invalide" {
    run ./$prog exemples/grille_mauvais_carac.txt
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "Erreur: grille de mots invalide, ne doit contenir que des lettres majuscules." ]
}



