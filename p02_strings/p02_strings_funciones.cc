/**
 * @file p02_strings_funciones.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Funciones complementarias del Main (Definicion)
 */


#include "p02_strings_funciones.h"
#include <fstream>
#include <iostream>
#include "Alphabet.h"
#include "String.h"

Alphabet OperacionAlfabeto(const String& renglon){
  return renglon.get_alfabeto();
}

size_t OperacionLongitud(const String& renglon){
  return renglon.Longitud();
}

String OperacionInversa(const String& renglon){
  return renglon.Inversa();
}

Language OperacionPrefijos(const String& renglon){
  return renglon.Prefijos();
}

Language OperacionSufijos(const String& renglon){
  return renglon.Sufijos();
}

bool OperacionValidacion(const String& renglon){
  return renglon.ValidarAlfabeto();
}