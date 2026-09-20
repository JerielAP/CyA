/**
 * @file Language.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Declaración de la clase "Language". Define la estructura Lenguaje
 */

#pragma once

#include <set>
#include "String.h"

class Language {
  public:
    void Insert(const String& cadena);
    void PrintLanguaje();
    friend std::ostream& operator<<(std::ostream& os, const Language& lenguaje);

  private:
    std::set<String> cadenas_;
};