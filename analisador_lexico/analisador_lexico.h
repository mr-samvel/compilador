#ifndef analisador_lexico_h
#define analisador_lexico_h

#include <vector>
#include <string>
#include <cctype>
#include <tuple>

#include "token.h"
#include "transicao/diagrama_de_transicao.h"
#include "transicao/fabrica_diagrama_de_transicao.h"

class AnalisadorLexico {
  public:
    AnalisadorLexico() : 
      _diagramas{
        FabricaDiagramaDeTransicao::get_diagrama_ident(),
        FabricaDiagramaDeTransicao::get_diagrama_int(),
        FabricaDiagramaDeTransicao::get_diagrama_float()
      }
    {}

    std::vector<TokenEnum> analisar(const std::string& input);

  private:
    bool eh_branco(char c) { return std::isspace(static_cast<unsigned char>(c)); };
    bool eh_nova_linha(char c) { return c == '\n'; };
    std::tuple<int, TokenEnum> _analisar_trecho(const int i, const std::string &input, DiagramaDeTransicao* diagrama);
    
  private:
    DiagramaDeTransicao* _diagramas[3];
};

#endif