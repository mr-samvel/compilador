#include "colecao_funcoes_de_transicao.h"

TransicaoChar* ColecaoFuncoesDeTransicao::_transicao_char = nullptr;
TransicaoDigito* ColecaoFuncoesDeTransicao::_transicao_digito = nullptr;
TransicaoLiteral* ColecaoFuncoesDeTransicao::_transicao_underline = nullptr;
TransicaoLiteral* ColecaoFuncoesDeTransicao::_transicao_ponto = nullptr;
TransicaoOutro* ColecaoFuncoesDeTransicao::_transicao_outro = nullptr;

TransicaoChar* ColecaoFuncoesDeTransicao::get_fn_transicao_char() {
    if (_transicao_char == nullptr) {
        _transicao_char = new TransicaoChar();
    }
    return _transicao_char;
}

TransicaoDigito* ColecaoFuncoesDeTransicao::get_fn_transicao_digito() {
    if (_transicao_digito == nullptr) {
        _transicao_digito = new TransicaoDigito();
    }
    return _transicao_digito;
}

TransicaoLiteral* ColecaoFuncoesDeTransicao::get_fn_transicao_underline() {
    if (_transicao_underline == nullptr) {
        _transicao_underline = new TransicaoLiteral('_');
    }
    return _transicao_underline;
}

TransicaoLiteral* ColecaoFuncoesDeTransicao::get_fn_transicao_ponto() {
    if (_transicao_ponto == nullptr) {
        _transicao_ponto = new TransicaoLiteral('.');
    }
    return _transicao_ponto;
}

TransicaoOutro* ColecaoFuncoesDeTransicao::get_fn_transicao_outro() {
    std::vector<FuncaoDeTransicao*> funcoes_de_transicao = {
        get_fn_transicao_char(),
        get_fn_transicao_digito(),
        get_fn_transicao_underline(),
        get_fn_transicao_ponto()
    };

    if (_transicao_outro == nullptr) {
        _transicao_outro = new TransicaoOutro(funcoes_de_transicao);
    }
    return _transicao_outro;
}