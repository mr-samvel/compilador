#ifndef transicao_outro_h
#define transicao_outro_h
#include <stdlib.h>
#include <vector>

#include "funcao_de_transicao.h"

class TransicaoOutro : public FuncaoDeTransicao {
  public:
    TransicaoOutro(std::vector<FuncaoDeTransicao*> funcoes_de_transicao)
      : _funcoes_de_transicao(funcoes_de_transicao) {};

    bool validar_transicao(char simbolo) override;

  private:
    std::vector<FuncaoDeTransicao*> _funcoes_de_transicao;
};

#endif