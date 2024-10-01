#ifndef funcao_de_transicao_h
#define funcao_de_transicao_h

#include <stdlib.h>

class FuncaoDeTransicao {
  public:
    virtual bool validar_transicao(char simbolo) = 0;
};

#endif