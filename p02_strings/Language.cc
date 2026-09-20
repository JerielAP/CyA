/**
 * @file Language.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Definicion de la clase "Language"
 */

#include "Language.h"


void Language::Insert(const String& cadena){
  cadenas_.insert(cadena);
}

std::ostream& operator<<(std::ostream& os, const Language& lenguaje){
  os << "{";
  bool primero = true;
  for(const String& cadena : lenguaje.cadenas_){
    if(!primero){
      os << ", ";
    }
    os << cadena;
    primero = false;
  }
  os << "}";
  return os;
}