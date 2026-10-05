/**
 * @file ***
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief ****
 *        
 *        
 */

#include "html_analyzer.h"
#include <fstream>
#include <iostream>


HtmlAnalyzer::HtmlAnalyzer()
    : doctype_regex_(R"(^\s*<!DOCTYPE\s+html\s*>$)", std::regex::optimize),
      tag_regex_(R"(<(/?)(html|head|title|body|h1|p|a|img)(.*?)\s*>)", std::regex::optimize),
      attribute_regex_(R"raw(([a-zA-Z_:][-a-zA-Z0-9_:.]*)\s*=\s*"([^"]*)")raw", std::regex::optimize),
      comment_regex_(R"(<!--[\s\S]*?-->)", std::regex::optimize) {}



std::vector<Attribute> HtmlAnalyzer::ExtractAttributes(const std::string& tag) {
  std::vector<Attribute> attributes;

  auto begin = std::sregex_iterator(tag.begin(), tag.end(), attribute_regex_); //Primera coincidencia
  auto end = std::sregex_iterator();                        //Justo despues de la ultima coincidencia

  for (auto i = begin; i != end; ++i) {
    std::smatch match = *i;
    Attribute attr;
    attr.name = match[1].str(); //Primer ()
    attr.value = match[2].str();//Segundo ()
    attributes.push_back(attr);
  }

  return attributes;
}


void HtmlAnalyzer::ProcessLine(const std::string& line, int line_number, HtmlDocument& doc){
  if (std::regex_match(line, doctype_regex_)) {
    doc.SetHasDoctype(true);
  }

  auto begin = std::sregex_iterator(line.begin(), line.end(), tag_regex_);
  auto end = std::sregex_iterator();
  
  for (auto i = begin; i != end; ++i) {
    std::smatch match = *i;
    Tag tag;
    tag.line = line_number;
    tag.name = match[1].str() + match[2].str(); // 1 = '/' 2 = nombre
    tag.attributes = ExtractAttributes(match[3].str());
    doc.AddTag(tag);
  }

}



HtmlDocument HtmlAnalyzer::Analyze(const std::string& filename) {
  HtmlDocument doc;
  doc.SetFilename(filename);
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: no se pudo abrir el archivo " << filename << "\n";
    return doc;
  }

  std::string line;
  size_t line_number{1};
  
  bool in_comment = false;
  size_t comment_start = 0;
  std::string comment_text;

  while (std::getline(file, line)) {
      if (in_comment) {
        comment_text += "\n" + line;
        if (line.find("-->") != std::string::npos) {
          Comment comment;
          comment.start_line = comment_start;
          comment.end_line = line_number;
          comment.text = comment_text;
          doc.AddComment(comment);
          in_comment = false;
        }
      } else {
        if (line.find("<!--") != std::string::npos) {
          if (line.find("-->") != std::string::npos) {
            Comment comment;
            comment.start_line = line_number;
            comment.end_line = line_number;
            comment.text = line;
            doc.AddComment(comment);
          } else {
            in_comment = true;
            comment_start = line_number;
            comment_text = line;
          }
        } else {
          ProcessLine(line, line_number, doc);
        }
      }
      line_number++;
    }

  return doc;
}