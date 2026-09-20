/**
 * @file Alphabet.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Clase que guarda los alfabetos (Interpreta un string
 *        para trasformarlo en un alfabeto basado en std::set)
 *        Uso principal: Saber si una cadena pertenece a un alfabeto
 */

#pragma once

#include <iostream>
#include <set>
#include <string>

class Alphabet {
    public:
        Alphabet(const std::string& cadena);

        bool Pertenece(char simbolo) const;

        friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

    private:
        std::set<char> simbolos_;
};