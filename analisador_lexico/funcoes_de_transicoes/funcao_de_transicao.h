#ifndef funcao_de_transicao_h
#define funcao_de_transicao_h

#include <stdlib.h>

class FuncaoDeTransicao {
  public:
    FuncaoDeTransicao();
    ~FuncaoDeTransicao();
    
    virtual bool validar_transicao(char simbolo);
};

#endif