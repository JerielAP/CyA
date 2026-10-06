/**
 * @file html_functions.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief Funciones auxiliares del main
 *        
 *        
 */

#pragma once
#include <iostream>
#include <fstream>
#include "html_document.h"

void GenerateReport(std::ostream& os, const HtmlDocument& doc);