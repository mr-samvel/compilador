#include "analisador_sintatico.h"

#include <iostream>
#include <sstream>
#include <vector>

std::unordered_map<std::tuple<std::string, std::string>, std::string, tuple_hash> AnalisadorSintatico::_TABELA_LL1 = {
  {std::make_tuple("0M", "S"), "S->B"},
  {std::make_tuple("0M", "B"), "B->0MC"},
  {std::make_tuple("1M", "S"), "S->B"},
  {std::make_tuple("1M", "B"), "B->1MC"},
  {std::make_tuple("0m", "C"), "C->0mB"},
  {std::make_tuple("1m", "C"), "C->1mB"},
  {std::make_tuple("0", "S"), "S->B"},
  {std::make_tuple("0", "B"), "B->0"},
  {std::make_tuple("0", "C"), "C->0"},
  {std::make_tuple("1", "S"), "S->B"},
  {std::make_tuple("1", "B"), "B->1"},
  {std::make_tuple("1", "C"), "C->1"},
  {std::make_tuple("0", "S"), "S->B"},
  {std::make_tuple("0", "B"), "B->0"},
  {std::make_tuple("$", "S"), "S->B"}
};

std::vector<std::string> split(const std::string &str) {
  std::vector<std::string> tokens;
  std::string token;
  std::stringstream ss(str);
  while (std::getline(ss, token, ' ')) {
    tokens.push_back(token);
  }
  return tokens;
}

bool AnalisadorSintatico::analisar(std::string sentenca) {
  sentenca += "$";

  std::vector<std::string> tokens = split(sentenca);

  int cursor = 0;
  std::stack<std::string> pilha;
  pilha.push("$"); pilha.push("S");

  std::string cabeca;
  while ((cabeca = pilha.top()) != "$") {
    std::string simbolo = tokens[cursor];
    
    if (cabeca == "$" && simbolo == "$") {
      return true;
    } else if (cabeca == simbolo) {
      pilha.pop();
      cursor++;
    } else {
      std::tuple<std::string, std::string> chave = std::make_tuple(simbolo, cabeca);
      if (_TABELA_LL1.find(chave) == _TABELA_LL1.end())
        return false;
      
      std::string producao = _TABELA_LL1.at(chave);
      // reverse a producao

      std::cout << producao << std::endl;

      pilha.pop();
      for (char p : producao)
        pilha.push(std::string(1, p));
    }
  }
}