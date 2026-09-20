/**
 * @file Alphabet.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Metodos desarrollados de la clase "Alphabet"
 */


#include <set>
#include <iostream>
#include "Alphabet.h"

Alphabet::Alphabet(const std::string& cadena) {
  for(size_t i{0}; i < cadena.size(); i++) {
    if(cadena.at(i) != '&'){
        simbolos_.insert(cadena.at(i));
    }
  }
  if (simbolos_.empty()){
    std::cerr << "Advertencia. Se ha creado un alfabeto sin elementos.\n";
  }
}

bool Alphabet::Pertenece(char simbolo) const {
  return simbolos_.count(simbolo);
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{";
  bool primero = true;

  for (char simbolo : alphabet.simbolos_) {
    if (!primero) {
      os << ", ";
    }
    os << simbolo;
    primero = false;
  }

  os << "}";
  return os;
}