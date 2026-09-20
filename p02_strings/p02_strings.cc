/**
 * @file p02_strings.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief Main: Programa de procesamiento de cadenas en funcion
 *        de la terea asignada mediante el OPCODE 1-6
 */

#include <iostream>
#include <fstream>
#include "Alphabet.h"
#include "String.h"
#include "Language.h"
#include "p02_strings_funciones.h"

int main(int argc, char* argv[]) {


  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "Esta herramienta analiza Cadenas.\n"
              << "Uso: ./p02_strings filein.txt fileout.txt opcode\n"
              << "opcode: 1.Alfabeto 2.Longitud 3.Inversa 4.Prefijos 5.Sufijos 6.Validación\n"
              << "Formato de documento esperado:\n"
              << "cadena alfabeto\n"
              << "Ejemplo:\n"
              << "abbab ab\n"
              << "hola ahlo\n"
              << "3112 123\n\n";
    return 0; 
  }

  if(argc != 4){
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n"
              << "Prube './p02_strings --help' para más información.\n";
    return 1;
  }

  
  std::ifstream fichero_entrada(argv[1]);
  std::ofstream fichero_salida(argv[2]);
  int opcode = std::stoi(argv[3]);

  if (!fichero_entrada.is_open() || !fichero_salida.is_open()) {
    std::cerr << "Error al abrir los ficheros. Revise el nombre de los mismos.\n";
    return 1;
  }
 
  std::string renglon;
  while(std::getline(fichero_entrada, renglon)){

    size_t posicion = renglon.find(' ');
    if(posicion == std::string::npos){
        std::cerr << "Error de formato del documento\n";
        return 1;
    }
    std::string texto_cadena = renglon.substr(0,posicion);
    std::string texto_alfabeto = renglon.substr(posicion + 1);

    Alphabet alfabeto(texto_alfabeto);
    String cadena(texto_cadena, alfabeto);

      switch(opcode){
        case(1):{
          Alphabet alfabeto_resultado = OperacionAlfabeto(cadena);
          fichero_salida << texto_cadena << ": " << alfabeto_resultado << "\n";
          break;
        }
        
        case(2):{
          size_t longitud_resultado = OperacionLongitud(cadena);
          fichero_salida << longitud_resultado << "\n";
          break;
        }
        
    
        case(3):{
          String inversa_resultado = OperacionInversa(cadena);
          fichero_salida << texto_cadena << " -> " << inversa_resultado << "\n";
          break;
        }
        
        case(4):{
          Language prefijos_resultado = OperacionPrefijos(cadena);
          fichero_salida << prefijos_resultado << "\n";
          break;
        }
        
        case(5):{
          Language sufijos_resultado = OperacionSufijos(cadena);
          fichero_salida << sufijos_resultado << "\n";
          break;
        }
        
        case(6):{
          bool validacion_resultado = OperacionValidacion(cadena);
          if(validacion_resultado){
            fichero_salida << "OK" << "\n";
          } else {
            fichero_salida << "ERROR" << "\n";
          }
          break;
        }
        
        default:
            std::cout << "OPCODE no valido\n";
            return 1;
      }
  }


  return 0;  
}