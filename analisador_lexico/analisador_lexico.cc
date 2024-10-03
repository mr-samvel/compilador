#include "analisador_lexico.h"
#include "transicao/fabrica_diagrama_de_transicao.h"
#include <stdlib.h>
#include <iostream>

std::vector<TokenEnum> AnalisadorLexico::analisar(const std::string &input) {
  std::vector<TokenEnum> tokens;
  std::string lexema;
  Estado* estado_atual = nullptr;

  for (size_t i = 0; i < input.length(); ++i) {
    char c = input[i];

    if (eh_branco(c) && lexema.empty()) {
      if (eh_nova_linha(c))
        tokens.push_back(TokenEnum::NOVA_LINHA);
      continue;
    }

    if (estado_atual == nullptr)
      estado_atual = _diagrama_ident->proximo_estado(_diagrama_ident->get_estado_inicial(), c);
    else 
      estado_atual = _diagrama_ident->proximo_estado(estado_atual, c);

    if (estado_atual == nullptr) {
      tokens.push_back(TokenEnum::OUTRO);
      lexema.clear();
      continue;
    }
    
    if (estado_atual->eh_final()) {
      if (estado_atual->eh_retorno_de_pilha())
        --i;
      else
        lexema += c;
      
      tokens.push_back(TokenEnum::IDENT);
      lexema.clear();
      estado_atual = nullptr;
    } else {
      lexema += c;
    }
  }

  return tokens;
}