/**
 * @file String.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Declaracion de la clase "String". Define las Cadenas
 *        Esta clase implementa la mayoria de los metodos necesarios
 *        para los OPCODEs de esta práctica
 */

#pragma once

#include <string>
#include "Alphabet.h"
//#include "Language.h" //Al incluirse dos clases entre si, la compilacion queda en bucle
class Language;         //Esto es una declaración adelantada, solventa el problema

class String{
  public:
    String(const std::string& texto, const Alphabet& alfabeto);

    size_t Longitud() const;
    String Inversa() const;
    bool ValidarAlfabeto() const;

    Language Prefijos() const;
    Language Sufijos() const;

    Alphabet get_alfabeto() const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    bool operator<(const String& otra) const;
  private:
    std::string texto_;
    Alphabet alfabeto_;
};