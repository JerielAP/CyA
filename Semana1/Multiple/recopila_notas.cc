/**
 * @file clase.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 14/09/2026
 * @brief Implementación de los métodos de la Clase "recopila_notas.h"
 */

#include "recopila_notas.h"

void RecopilaNotas::Agregar_Nota(std::string alumno, double nota) {
  calificaciones[alumno].push_back(nota);
}

void RecopilaNotas::Imprimir_Calificaciones() {
  for (const auto& elemento : calificaciones) {
    std::cout << elemento.first << ": ";
    for(double nota : elemento.second){
      std::cout << nota << " ";
    }
    std::cout << std::endl;
  }
}

void RecopilaNotas::Calificacion_Alu(std::string alumno) {
  bool encontrado{false};
  for (const auto& elemento : calificaciones) {
    if(elemento.first == alumno){
      double max = elemento.second.at(0);
      for(double nota : elemento.second){
        if(max < nota){
          max = nota;
        }
      }
    std::cout << "La calificación máxima es " << max << std::endl;
    encontrado = true;
    }
  }
  if(!encontrado){
    std::cout << "No se ha encontrado el estudiante " << alumno << std::endl;
  }
}


