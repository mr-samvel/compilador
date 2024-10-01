#ifndef token_h
#define token_h

#include <string>

enum class TokenEnum {
  IDENT,
  OUTRO
};

const std::string token_to_string(TokenEnum token);

// enum class TokenTipo {
//   IDENT,
//   OUTRO
// };

// class Token {
//   public:
//     Token(TokenTipo tipo, const std::string& lexema)
//       : _tipo(tipo), _lexema(lexema) {}

//     TokenTipo get_tipo() const { return _tipo; }
//     std::string get_lexema() const { return _lexema; }

//   private:
//     TokenTipo _tipo;
//     std::string _lexema;
// };

#endif