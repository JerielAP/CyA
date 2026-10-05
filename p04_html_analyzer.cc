/**
 * @file ***
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief ****
 *        
 *        
 */

#include <iostream>
#include <fstream>
#include <string>
#include "html_functions.h"
#include "html_document.h"
#include "html_analyzer.h"


int main(int argc, char* argv[]){
    
  if(argc == 2 && std::string(argv[1]) == "--help"){
    std::cout << "Este programa está destinado al procesamiento de archivos HTML,\n" 
              << "el uso es: ./p04_html_analyzer pagina.html esquema.txt\n";
    return 0;
  }

  if(argc != 3){
    std::cerr << "Uso correcto: ./p04_html_analyzer pagina.html esquema.txt\n"
              << "Para información a cerca del programa use: \n"
              << "./p04_html_analyzer --help \n";
    return 1;
  }

  std::ofstream fichero_salida (argv[2]);

  if (!fichero_salida.is_open()) {
    std::cerr << "Error al abrir el fichero de salida: " << argv[2] << ".\n";
    return 1;
  }

  HtmlAnalyzer analizador;
  HtmlDocument documento = analizador.Analyze(argv[1]);
  GenerateReport(fichero_salida, documento);
  GenerateReport(std::cout, documento);

  return 0;
}