/**
 * @file clase.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 14/09/2026
 * @brief Clase cuya función es procesar las notas de varios alumnos y devolver la mayor de cada uno
 */

#ifndef PROCESA_NOTAS_H
#define PROCESA_NOTAS_H

#include <iostream>
#include <string>
#include <map>

class ProcesaNotas {
 private:

  std::map<std::string, double> calificaciones;

 public:
  void Agregar_Nota(std::string alumno, double nota);
  void Imprimir_Calificaciones();

};

#endif