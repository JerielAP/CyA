/**
 * @file html_functions
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief Metodos auxiliares del main
 *        
 *        
 */

#include "html_functions.h"
#include "html_document.h"
#include <iostream>

void GenerateReport(std::ostream& os, const HtmlDocument& doc){
  os << "PROGRAM: " << doc.GetFilename() << "\n" 
  << "DESCRIPTION:\n" << doc.GetDescription()
  << "\n\n"
  << "STRUCTURE:" 
  << "\nHTML: " << (doc.GetHasHtml() ? "True" : "False")
  << "\nHEAD: " << (doc.GetHasHead() ? "True" : "False") 
  << "\nBODY: "<< (doc.GetHasBody() ? "True" : "False")
  << "\nDOCTYPE: " << (doc.GetHasDoctype() ? "HTML5" : "False") 
  << "\n\n"

  << "TAGS: \n";
  for (const auto& tag : doc.GetTags()){
      os << "[Line " << tag.line << "] " << tag.name << "\n";
  }
 
  os << "\n\nATTRIBUTES:\n";

  for (const auto& tag : doc.GetTags()) {
    if (!tag.attributes.empty()) {
      os << "[Line " << tag.line << "] " << tag.name << "\n";
      for (const auto& attr : tag.attributes) {
        os << attr.name << "=\"" << attr.value << "\"\n";
      }
      os << "\n\n";
    }
  }
  
  os << "COMMENTS:\n";
  for (const auto& comment : doc.GetComments()) {
    if(comment.start_line == comment.end_line){
      os << "[Line " << comment.start_line << "]\n";
    } else {
      os << "[Line " << comment.start_line << "-" << comment.end_line << "]\n";
    }

    if (comment.is_description) {
      os << "DESCRIPTION\n";
    }

    os << comment.text << "\n\n";
  }

}
