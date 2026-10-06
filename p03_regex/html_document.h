/**
 * @file html_document.h
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief Clase destinada a guardar los datos de un archivo html
 *        
 *        
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Attribute {
  std::string name;
  std::string value;
};

struct Tag {
  int line;
  std::string name;
  std::vector<Attribute> attributes;
};

struct Comment {
  int start_line;
  int end_line;
  std::string text;
  bool is_description = false;
};



class HtmlDocument {
  public:

    void SetHasDoctype(bool);
    void SetHasBody(bool);
    void SetHasHead(bool);
    void SetHasHtml(bool);

    void SetFilename(const std::string& filename);
    void SetDescription(const std::string& desc);
    void AddTag(const Tag& tag);
    void AddComment(Comment& comment);


    bool GetHasDoctype() const;
    bool GetHasBody() const;
    bool GetHasHead() const;
    bool GetHasHtml() const;

    const std::string& GetFilename() const;
    const std::string& GetDescription() const;
    const std::vector<Tag>& GetTags() const;
    const std::vector<Comment>& GetComments() const;
    
  private:
    std::string filename_;
    std::string description_;
    bool has_html_ = false;
    bool has_head_ = false;
    bool has_body_ = false;
    bool has_doctype_ = false;

    std::vector<Tag> tags_;
    std::vector<Comment> comments_;
};

