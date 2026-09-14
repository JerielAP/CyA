/**
 * @file clase.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 14/09/2026
 * @brief Clase para procesar las notas de los alumnos e imprimirlas todas seguidas (no solo la maxima)
 */

#ifndef RECOPILA_NOTAS_H
#define RECOPILA_NOTAS_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

class RecopilaNotas {
 private:

  std::map<std::string, std::vector<double>> calificaciones;

 public:
  void Agregar_Nota(std::string alumno, double nota);
  void Imprimir_Calificaciones();

};

#endif