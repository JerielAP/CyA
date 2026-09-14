/**
 * @file p01_single_grades.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 14/09/2026
 * @brief Main que abre el archivo donde se encuentran los datos de cada alumno y mediante la clase
 *        se queda con las mayores notas y las imprime
 */

#include <iostream>
#include <fstream>
#include "procesa_notas.h"

int main(int argc, char* argv[]) {

  if(argc == 1){
    std::cout << "Modo de empleo: ./p01_single_grades grades.txt\n";
    return 1;
  }

if (std::string(argv[1]) == "--help") {
    std::cout << "Esta herramienta procesa notas y guarda la mayor.\n"
              << "Uso: ./p01_single_grades grades.txt\n"
              << "Formato de documento esperado:\n"
              << "alu01010101 4.5\n"
              << "alu02020202 9.5\n";
    return 0; 
  }

  std::ifstream archivo(argv[1]);
  if (!archivo.is_open()) {
    std::cerr << "Imposible abrir archivo, compruebe el nombre\n";
    return 1;
  }

  ProcesaNotas mis_notas;
  std::string linea;

  while (std::getline(archivo, linea)) {
    size_t posicion_espacio = linea.find(' ');
    std::string alumno_leido = linea.substr(0, posicion_espacio);      //Extraemos nombre
    double nota_leida = std::stod(linea.substr(posicion_espacio + 1)); //Extraemos nota

    mis_notas.Agregar_Nota(alumno_leido, nota_leida);
  }

  mis_notas.Imprimir_Calificaciones();


  std::cout << "Si desea introducir un alumno mas, teclee a continuacion su información:\n";
  std::string nombre;
  double nota = -1;
  std::cin >> nombre >> nota;
  if (nota != -1) {
    mis_notas.Agregar_Nota(nombre, nota);
  }

  mis_notas.Imprimir_Calificaciones();

  return 0;
}