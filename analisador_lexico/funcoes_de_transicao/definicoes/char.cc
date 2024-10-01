#include "char.h"
#include <cctype>

bool TransicaoChar::validar_transicao(char simbolo) {
    // // [65 - 90] : A - Z; [97 - 122] : a - z
    // if (simbolo >= 65 && simbolo <= 90 || simbolo >= 97 && simbolo <= 122)
    //   return true;
    // return false;
    return std::isalpha(static_cast<unsigned char>(simbolo));
}