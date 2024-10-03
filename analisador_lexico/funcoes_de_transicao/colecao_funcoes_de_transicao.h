#ifndef COLECAO_FUNCOES_DE_TRANSICAO_H
#define COLECAO_FUNCOES_DE_TRANSICAO_H

#include "definicoes/char.h"
#include "definicoes/digito.h"
#include "definicoes/literal.h"
#include "definicoes/outro.h"

class ColecaoFuncoesDeTransicao {
  public:
    static TransicaoChar* get_fn_transicao_char();
    static TransicaoDigito* get_fn_transicao_digito();
    static TransicaoLiteral* get_fn_transicao_underline();
    static TransicaoLiteral* get_fn_transicao_ponto();
    static TransicaoOutro* get_fn_transicao_outro();

  private:
    ColecaoFuncoesDeTransicao() = delete;  // Previne instanciação, esta é uma classe estática
    
  private:
    static TransicaoChar* _transicao_char;
    static TransicaoDigito* _transicao_digito;
    static TransicaoLiteral* _transicao_underline;
    static TransicaoLiteral* _transicao_ponto;
    static TransicaoOutro* _transicao_outro;
};

#endif