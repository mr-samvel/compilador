#include "diagrama_de_transicao.h"

Estado* DiagramaDeTransicao::proximo_estado(Estado* atual, char simbolo) {
  std::set<Transicao*> transicoes = this->transicoes(atual);
  for (Transicao* transicao : transicoes) if (transicao->transicao_eh_valida(simbolo))
    return transicao->get_fim();
}

std::set<Transicao*> DiagramaDeTransicao::transicoes(Estado* estado) {
  std::set<Transicao*> transicoes;
  for (Transicao* transicao : _transicoes) if (transicao->get_origem() == estado)
    transicoes.insert(transicao);
  return transicoes;
}

DiagramaDeTransicao::~DiagramaDeTransicao() {}