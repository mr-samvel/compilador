#ifndef transicao_literal_h
#define transicao_literal_h
#include "funcao_de_transicao.h"

class TransicaoLiteral : public FuncaoDeTransicao {
  public:
    TransicaoLiteral(char simbolo_de_transicao)
      : _simbolo_de_transicao(simbolo_de_transicao) {};

    bool validar_transicao(char simbolo);

  private:
    char _simbolo_de_transicao;
};

#endif