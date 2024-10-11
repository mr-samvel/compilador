#ifndef ANALISADOR_SINTATICO_H
#define ANALISADOR_SINTATICO_H

#include <tuple>
#include <unordered_map>
#include <stack>
#include <string>

// #include "analisador_lexico/transicao/transicao.h"

struct tuple_hash {
    template <typename T1, typename T2>
    std::size_t operator() (const std::tuple<T1, T2>& t) const {
        auto h1 = std::hash<T1>{}(std::get<0>(t));
        auto h2 = std::hash<T2>{}(std::get<1>(t));
        return h1 ^ (h2 << 1);
    }
};

class AnalisadorSintatico {
  public:
    bool analisar(std::string input);

  private:
    AnalisadorSintatico() = delete;
    
  private:
    // substituir utilizando a classe Transicao 
    static std::unordered_map<std::tuple<std::string, std::string>, std::string, tuple_hash> _TABELA_LL1;
};

#endif