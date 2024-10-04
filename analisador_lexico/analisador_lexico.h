#ifndef analisador_lexico_h
#define analisador_lexico_h

#include <vector>
#include <string>
#include <cctype>
#include <tuple>
#include <unordered_map>

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
      },
      _palavras_reservadas{
        "def", "int", "float", "string", "break",
        "if", "else", "new", "for", "return", "print",
        "read", "null"
      }
    {}

    std::vector<TokenEnum> analisar(const std::string& input);
    std::string tabela_de_simbolos_to_string();

  private:
    bool eh_branco(char c) { return std::isspace(static_cast<unsigned char>(c)); };
    bool eh_nova_linha(char c) { return c == '\n'; };
    std::tuple<int, TokenEnum> _analisar_trecho(const int i, const std::string &input, DiagramaDeTransicao* diagrama, int linha_atual);
    
  private:
    DiagramaDeTransicao* _diagramas[3];
    std::set<std::string> _palavras_reservadas;
    std::unordered_map<std::string, std::set<int>> _tabela_de_simbolos;
};

#endif