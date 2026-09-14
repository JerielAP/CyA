/**
 * @file clase.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 14/09/2026
 * @brief Implementación de los métodos de la Clase "procesa_notas"
 */

#include "procesa_notas.h"

void ProcesaNotas::Agregar_Nota(std::string alumno, double nota) {
  if(calificaciones[alumno] < nota){
    calificaciones[alumno] = nota;
  }
}

void ProcesaNotas::Imprimir_Calificaciones() {
  for (const auto& elemento : calificaciones) {
    std::cout << elemento.first << " " << elemento.second << "\n";
  }
}
