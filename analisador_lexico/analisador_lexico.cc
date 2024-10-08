#include <functional>
#include <algorithm>
#include <thread>
#include <future>
#include <sstream>

#include "analisador_lexico.h"
#include "transicao/fabrica_diagrama_de_transicao.h"

std::vector<TokenEnum> AnalisadorLexico::analisar(const std::string &input) {
  std::vector<TokenEnum> tokens;
  std::vector<int> i_obtidos;
  std::vector<TokenEnum> tokens_obtidos;
  int linha_atual = 1;

  for (size_t i = 0; i < input.length(); i++) {
    if (eh_branco(input[i])) {
      if (eh_nova_linha(input[i])) {
        tokens.push_back(TokenEnum::NOVA_LINHA);
        linha_atual++;
      }
      continue;
    }
    
    std::vector<std::future<std::tuple<int, TokenEnum>>> futures;
    for (DiagramaDeTransicao* diagrama : _diagramas)
      futures.push_back(std::async(std::launch::async, &AnalisadorLexico::_analisar_trecho, this, i, std::ref(input), diagrama, linha_atual));

    for (auto& future : futures) {
      std::tuple<int, TokenEnum> result = future.get();
      i_obtidos.push_back(std::get<0>(result));
      tokens_obtidos.push_back(std::get<1>(result));
    }

    auto it_tokens_obtidos = std::find_if(tokens_obtidos.begin(), tokens_obtidos.end(), [](TokenEnum t) {
      return t != TokenEnum::OUTRO;
    });

    if (it_tokens_obtidos != tokens_obtidos.end()) {
      size_t idx = std::distance(tokens_obtidos.begin(), it_tokens_obtidos);
      tokens.push_back(tokens_obtidos[idx]);
      i = i_obtidos[idx];
    } else {
      tokens.push_back(tokens_obtidos[0]);
      auto it = std::max_element(i_obtidos.begin(), i_obtidos.end());
      i = i_obtidos[std::distance(i_obtidos.begin(), it)];
    }

    i_obtidos.clear();
    tokens_obtidos.clear();
  }

  return tokens;
}

std::tuple<int, TokenEnum> AnalisadorLexico::_analisar_trecho(const int k, const std::string &input, DiagramaDeTransicao* diagrama, int linha_atual) {
  std::string lexema;
  Estado* estado_atual = nullptr;

  for (size_t i = k; i < input.length(); ++i) {
    char c = input[i];

    if (estado_atual == nullptr)
      estado_atual = diagrama->proximo_estado(diagrama->get_estado_inicial(), c);
    else 
      estado_atual = diagrama->proximo_estado(estado_atual, c);

    if (estado_atual == nullptr)
      return std::tuple<int, TokenEnum> (i, TokenEnum::OUTRO);
    
    if (estado_atual->eh_final()) {
      if (estado_atual->eh_retorno_de_pilha())
        --i;

      if (diagrama->get_token() == TokenEnum::IDENT) {
        if (_palavras_reservadas.find(lexema) != _palavras_reservadas.end())
          return std::tuple<int, TokenEnum> (i, TokenEnum::PALAVRA_RESERVADA);
        else
          if (_tabela_de_simbolos.find(lexema) != _tabela_de_simbolos.end())
            _tabela_de_simbolos[lexema].insert(linha_atual);
          else
            _tabela_de_simbolos[lexema] = {linha_atual};
      }

      return std::tuple<int, TokenEnum> (i, diagrama->get_token());
    } else {
      lexema += c;
    }
  }
}

std::string AnalisadorLexico::tabela_de_simbolos_to_string() {
  std::stringstream ss;
  for (const auto& par : _tabela_de_simbolos) {
    ss << par.first << ": [";
    for (auto it = par.second.begin(); it != par.second.end(); ++it) {
      ss << *it;
      if (std::next(it) != par.second.end())
        ss << ", ";
    }
    ss << "]\n";
  }
  return ss.str();
}