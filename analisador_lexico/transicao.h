#ifndef transicao_h
#define transicao_h

#include "estado.h"
#include "funcoes_de_transicoes/funcao_de_transicao.h"

class Transicao {
  public:
    Transicao(Estado* origem, FuncaoDeTransicao* transicao, Estado* fim): 
      _origem(origem), _transicao(transicao), _fim(fim) {};

    ~Transicao();
    
    Estado* get_origem() { return _origem; };
    Estado* get_fim() { return _fim; };
    bool transicao_eh_valida(char simbolo) { return _transicao->validar_transicao(simbolo); };

  private:
    Estado* _origem;
    Estado* _fim;
    FuncaoDeTransicao* _transicao;
};

#endif