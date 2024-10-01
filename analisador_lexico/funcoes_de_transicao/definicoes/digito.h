#ifndef transicao_digito_h
#define transicao_digito_h

#include "funcao_de_transicao.h"

class TransicaoDigito : public FuncaoDeTransicao {
  public:
    bool validar_transicao(char simbolo) override;
};

#endif