#include "token.h"

const std::string token_to_string(TokenEnum token) {
  switch (token) {
    case TokenEnum::IDENT:
      return "IDENT";
    case TokenEnum::OUTRO:
      return "OUTRO";
  }
}