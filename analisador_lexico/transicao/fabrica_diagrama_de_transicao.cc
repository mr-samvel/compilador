#include <vector>

#include "diagrama_de_transicao.h"
#include "fabrica_diagrama_de_transicao.h"
#include "../funcoes_de_transicao/colecao_funcoes_de_transicao.h"
#include "estado.h"
#include "transicao.h"

DiagramaDeTransicao* FabricaDiagramaDeTransicao::get_diagrama_ident() {
  std::vector<Estado*> estados = {
    new Estado(true, false, false),
    new Estado(false, false, false),
    new Estado(false, true, true)
  };

  TransicaoChar* transicao_char = ColecaoFuncoesDeTransicao::get_fn_transicao_char();
  TransicaoDigito* transicao_digito = ColecaoFuncoesDeTransicao::get_fn_transicao_digito();
  TransicaoLiteral* transicao_underline = ColecaoFuncoesDeTransicao::get_fn_transicao_underline();
  TransicaoOutro* transicao_outro = ColecaoFuncoesDeTransicao::get_fn_transicao_outro();

  std::set<Transicao*> transicoes = {
    new Transicao(estados[0], transicao_char, estados[1]),
    new Transicao(estados[0], transicao_underline, estados[1]),
    new Transicao(estados[1], transicao_digito, estados[1]),
    new Transicao(estados[1], transicao_char, estados[1]),
    new Transicao(estados[1], transicao_underline, estados[1]),
    new Transicao(estados[1], transicao_outro, estados[2])
  };

  return new DiagramaDeTransicao(transicoes, estados[0], {estados[2]}, TokenEnum::IDENT);
}

DiagramaDeTransicao* FabricaDiagramaDeTransicao::get_diagrama_int() {
  std::vector<Estado*> estados = {
    new Estado(true, false, false),
    new Estado(false, false, false),
    new Estado(false, true, true)
  };

  TransicaoDigito* transicao_digito = ColecaoFuncoesDeTransicao::get_fn_transicao_digito();
  TransicaoOutro* transicao_outro = ColecaoFuncoesDeTransicao::get_fn_transicao_outro();

  std::set<Transicao*> transicoes = {
    new Transicao(estados[0], transicao_digito, estados[1]),
    new Transicao(estados[1], transicao_digito, estados[1]),
    new Transicao(estados[1], transicao_outro, estados[2])
  };

  return new DiagramaDeTransicao(transicoes, estados[0], {estados[2]}, TokenEnum::NI);
}

DiagramaDeTransicao* FabricaDiagramaDeTransicao::get_diagrama_float() {
  std::vector<Estado*> estados = {
    new Estado(true, false, false),
    new Estado(false, false, false),
    new Estado(false, false, false),
    new Estado(false, true, true)
  };

  TransicaoDigito* transicao_digito = ColecaoFuncoesDeTransicao::get_fn_transicao_digito();
  TransicaoLiteral* transicao_ponto = ColecaoFuncoesDeTransicao::get_fn_transicao_ponto();
  TransicaoOutro* transicao_outro = ColecaoFuncoesDeTransicao::get_fn_transicao_outro();

  std::set<Transicao*> transicoes = {
    new Transicao(estados[0], transicao_digito, estados[1]),
    new Transicao(estados[1], transicao_digito, estados[1]),
    new Transicao(estados[1], transicao_ponto, estados[2]),
    new Transicao(estados[2], transicao_digito, estados[2]),
    new Transicao(estados[2], transicao_outro, estados[3]),
  };

  return new DiagramaDeTransicao(transicoes, estados[0], {estados[3]}, TokenEnum::NPF);
}