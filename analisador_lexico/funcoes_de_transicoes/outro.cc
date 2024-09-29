#include <stdlib.h>
#include <functional>
#include <algorithm>
#include "outro.h"

bool TransicaoOutro::validar_transicao(char simbolo) {
  return !std::any_of(_funcoes_de_transicao.begin(), _funcoes_de_transicao.end(), [simbolo](FuncaoDeTransicao* func) {
    return func->validar_transicao(simbolo);
  });
}