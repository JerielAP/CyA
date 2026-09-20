/**
 * @file p02_strings_funciones.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Funciones complementarias del Main (Declaracion)
 */

 
#pragma once
#include <string>
#include "Language.h"

Alphabet OperacionAlfabeto(const String& renglon);
size_t OperacionLongitud(const String& renglon);
String OperacionInversa(const String& renglon);
Language OperacionPrefijos(const String& renglon);
Language OperacionSufijos(const String& renglon);
bool OperacionValidacion(const String& renglon);