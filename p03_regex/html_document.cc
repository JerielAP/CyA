/**
 * @file html_document.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 5/10/2026
 * @brief Implementacion de la clase
 *        
 *        
 */


#include "html_document.h"

void HtmlDocument::SetFilename(const std::string& filename) { filename_ = filename; }
void HtmlDocument::SetDescription(const std::string& desc) { description_ = desc; }

void HtmlDocument::SetHasDoctype(bool dt) { has_doctype_ = dt; }
void HtmlDocument::SetHasBody(bool bd) { has_body_ = bd; } 
void HtmlDocument::SetHasHead(bool hd) { has_head_ = hd; }
void HtmlDocument::SetHasHtml(bool ht) { has_html_ = ht; }

bool HtmlDocument::GetHasDoctype() const { return has_doctype_; }
bool HtmlDocument::GetHasBody() const { return has_body_; }
bool HtmlDocument::GetHasHead() const { return has_head_; }
bool HtmlDocument::GetHasHtml() const { return has_html_; }

const std::string& HtmlDocument::GetFilename() const { return filename_; }
const std::string& HtmlDocument::GetDescription() const { return description_; }
const std::vector<Tag>& HtmlDocument::GetTags() const { return tags_; }
const std::vector<Comment>& HtmlDocument::GetComments() const { return comments_; }

void HtmlDocument::AddTag(const Tag& tag){
         if (tag.name == "html") {
    has_html_ = true;
  } else if (tag.name == "head") {
    has_head_ = true;
  } else if (tag.name == "body") {
    has_body_ = true;
  }
  tags_.push_back(tag);
}

void HtmlDocument::AddComment(Comment& comment) {
  if (description_.empty()) {
    std::string clean = comment.text;

    size_t start = clean.find("<!--");
    if (start != std::string::npos) clean.erase(start, 4);

    size_t end = clean.rfind("-->");
    if (end != std::string::npos) clean.erase(end, 3);

    size_t first = clean.find_first_not_of(" \t\r\n");
    size_t last = clean.find_last_not_of(" \t\r\n");
    if (first != std::string::npos) {
      clean = clean.substr(first, last - first + 1);
    }

    description_ = clean;
    comment.is_description = true;
  }

  comments_.emplace_back(comment);
}