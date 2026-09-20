/**
 * @file String.cc
 * @author Jeriel Afonso Palenzuela (alu0101822761@ull.edu.es)
 * @date 22/09/2026
 * @brief 
 */


#include "String.h"
#include "Language.h"

String::String(const std::string& texto, const Alphabet& alfabeto) :
                texto_(texto), alfabeto_(alfabeto){}

size_t String::Longitud() const {
  if(texto_ == "&"){
    return 0;
  } else {
  return texto_.size();
  }
}

String String::Inversa() const {
  if(texto_ == "&"){
    return *this;
  } else {
    std::string cadena_aux;
    for(char char_aux : texto_){
        cadena_aux = char_aux + cadena_aux;     //Ponemos el caracter delante de lo que ya tenemos
    }
    return String(cadena_aux , alfabeto_);
  }
}

bool String::ValidarAlfabeto() const{
  if(texto_ == "&"){
    return true;
  }

  for(char char_aux : texto_){
    if(!alfabeto_.Pertenece(char_aux)){
        return false;
    }
  }
  return true;
}

Language String::Prefijos() const{
  Language resultado;
  resultado.Insert(String("&", alfabeto_));
  if (texto_ != "&"){
    for(size_t i{1}; i <= texto_.size(); ++i){
      resultado.Insert(String(texto_.substr(0,i), alfabeto_));
    } 
  }
  return resultado;
}

Language String::Sufijos() const{
  Language resultado;
  resultado.Insert(String("&", alfabeto_));
  if (texto_ != "&"){
    for(size_t i{0}; i < texto_.size(); ++i){
      resultado.Insert(String(texto_.substr(i), alfabeto_));
    } 
  }
  return resultado;
}

Alphabet String::get_alfabeto() const{
    return alfabeto_;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
  os << str.texto_;
  return os;
}

bool String::operator<(const String& otra) const {
  return texto_ < otra.texto_;
}