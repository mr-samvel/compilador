#include <stdlib.h>
#include <vector>

#include "diagrama_de_transicao.h"
#include "funcoes_de_transicoes/char.h"
#include "funcoes_de_transicoes/digito.h"
#include "funcoes_de_transicoes/literal.h"
#include "funcoes_de_transicoes/outro.h"
#include "estado.h"
#include "transicao.h"

std::vector<Estado *> estados = {
  new Estado(true, false, false),
  new Estado(false, false, false),
  new Estado(false, true, true)
};

TransicaoChar* transicao_char = new TransicaoChar();
TransicaoDigito* transicao_digito = new TransicaoDigito();
TransicaoLiteral* transicao_underline = new TransicaoLiteral('_');
TransicaoOutro* transicao_outro = new TransicaoOutro({transicao_char, transicao_digito, transicao_underline});

std::set<Transicao *> transicoes = {
  new Transicao(estados[0], transicao_char, estados[1]),
  new Transicao(estados[0], transicao_underline, estados[1]),
  new Transicao(estados[1], transicao_digito, estados[1]),
  new Transicao(estados[1], transicao_char, estados[1]),
  new Transicao(estados[1], transicao_underline, estados[1]),
  new Transicao(estados[1], transicao_outro, estados[2])
};

DiagramaDeTransicao* ident = new DiagramaDeTransicao(transicoes);

// desalocar news