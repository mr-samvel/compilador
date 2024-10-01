#include <iostream>
#include <fstream>
#include <sstream>

#include "analisador_lexico/analisador_lexico.h"
#include "analisador_lexico/token.h"

int main() {
  std::ifstream input_file("input");
  if (!input_file.is_open()) {
    std::cerr << "Não foi possível abrir o arquivo!" << std::endl;
    return 1;
  }

  std::stringstream buffer;
  buffer << input_file.rdbuf();
  
  std::string input = buffer.str();

  input_file.close();

  AnalisadorLexico analisador_lexico;
  std::vector<TokenEnum> tokens = analisador_lexico.analisar(input);

  for (const auto& token : tokens)
    std::cout << token_to_string(token) << " ";
  
  std::cout << std::endl;

  return 0;
}