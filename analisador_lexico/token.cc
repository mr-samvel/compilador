#include "token.h"

const std::string token_to_string(TokenEnum token) {
  switch (token) {
    case TokenEnum::IDENT:
      return "IDENT";
    case TokenEnum::PALAVRA_RESERVADA:
      return "PR";
    case TokenEnum::OUTRO:
      return "OUTRO";
    case TokenEnum::NOVA_LINHA:
      return "\n";
    case TokenEnum::NI:
      return "NI";
    case TokenEnum::NPF:
      return "NPF";
  }
}