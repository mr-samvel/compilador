#include "analisador_lexico.h"
#include "transicao/fabrica_diagrama_de_transicao.h"

std::vector<TokenEnum> AnalisadorLexico::analisar(const std::string &input) {
  std::vector<TokenEnum> tokens;
  std::string lexema;
  Estado* estado_atual = nullptr;

  for (size_t i = 0; i < input.length(); ++i) {
    char c = input[i];

    if (eh_branco(c)) {
      if (!lexema.empty()) {
        tokens.push_back(estado_atual && estado_atual->eh_final() ? TokenEnum::IDENT : TokenEnum::OUTRO);
        lexema.clear();
        estado_atual = nullptr;
      }
      continue;
    }

    if (estado_atual == nullptr)
      estado_atual = _diagrama_ident->proximo_estado(_diagrama_ident->get_estado_inicial(), c);
    else 
      estado_atual = _diagrama_ident->proximo_estado(estado_atual, c);
    
    lexema += c;

    if (estado_atual->eh_final()) {
      tokens.push_back(TokenEnum::IDENT);
      lexema.clear();
      estado_atual = nullptr;
    }
  }

  return tokens;
}