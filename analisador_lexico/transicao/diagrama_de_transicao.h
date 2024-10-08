#ifndef diagrama_de_transicao_h
#define diagrama_de_transicao_h

#include <stdlib.h>
#include <set>
#include <list>

#include "estado.h"
#include "transicao.h"
#include "../token.h"


class DiagramaDeTransicao {
  public:
    DiagramaDeTransicao(std::set<Transicao*> transicoes, Estado* estado_inicial, std::set<Estado*> estados_finais, TokenEnum token)
      : _transicoes(transicoes), _estado_inicial(estado_inicial), _estados_finais(estados_finais), _token(token) {};

    Estado* get_estado_inicial() { return _estado_inicial; };
    std::set<Estado*> get_estados_finais() { return _estados_finais; };
    TokenEnum get_token() { return _token; };
    
    Estado* proximo_estado(Estado* atual, char simbolo);

  private:
    std::set<Transicao*> transicoes(Estado* estado);

  private:
    // std::set<Estado> _estados;
    std::set<Transicao*> _transicoes;
    Estado* _estado_inicial;
    std::set<Estado*> _estados_finais;
    TokenEnum _token;
};

#endif