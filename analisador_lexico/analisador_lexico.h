#ifndef analisador_lexico_h
#define analisador_lexico_h

#include <vector>
#include <string>
#include <cctype>

#include "token.h"
#include "transicao/diagrama_de_transicao.h"
#include "transicao/fabrica_diagrama_de_transicao.h"

class AnalisadorLexico {
  public:
    AnalisadorLexico()
      : _diagrama_ident(FabricaDiagramaDeTransicao::get_diagrama_ident()) {}

    std::vector<TokenEnum> analisar(const std::string& input);

  private:
    bool eh_branco(char c) { return std::isspace(static_cast<unsigned char>(c)); };
    
  private:
    DiagramaDeTransicao* _diagrama_ident;
};

#endif