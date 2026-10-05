/**
 * @file ***
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief ****
 *        
 *        
 */



#pragma once

#include <regex>
#include <string>
#include "html_document.h"

class HtmlAnalyzer {
 public:
   HtmlAnalyzer();
   HtmlDocument Analyze(const std::string& name);
 
 private:
 
   void ProcessLine(const std::string& line, int line_number, HtmlDocument& doc);
   std::vector<Attribute> ExtractAttributes(const std::string& tag_content);
 
   std::regex doctype_regex_;
   std::regex tag_regex_;
   std::regex attribute_regex_;
   std::regex comment_regex_;
};