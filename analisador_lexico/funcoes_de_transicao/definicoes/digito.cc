#include "digito.h"
#include <cctype>

bool TransicaoDigito::validar_transicao(char simbolo) {
    // // [48 - 57] : 0 - 9;
    // if (simbolo >= 48 && simbolo <= 57)
    //   return true;
    // return false;
    return std::isdigit(static_cast<unsigned char>(simbolo));
}