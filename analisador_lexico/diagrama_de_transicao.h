#ifndef diagrama_de_transicao_h
#define diagrama_de_transicao_h

#include "estado.h"
#include "transicao.h"
#include <stdlib.h>
#include <set>
#include <list>


class DiagramaDeTransicao {
  public:
    DiagramaDeTransicao(std::set<Transicao*> transicoes)
      : _transicoes(transicoes) {};
      
    ~DiagramaDeTransicao();

    Estado* proximo_estado(Estado* atual, char simbolo);

  private:
    std::set<Transicao*> transicoes(Estado* estado);

  private:
    // std::set<Estado> _estados;
    std::set<Transicao*> _transicoes;
};

#endif