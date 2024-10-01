#ifndef transicao_char_h
#define transicao_char_h

#include "funcao_de_transicao.h"

class TransicaoChar : public FuncaoDeTransicao {
  public:
    bool validar_transicao(char simbolo) override;
};

#endif