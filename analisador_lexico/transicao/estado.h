#ifndef estado_h
#define estado_h

class Estado {
  public:
    Estado(bool eh_inicial, bool eh_final, bool eh_retorno_de_pilha)
     : _inicial(eh_inicial), _final(eh_final), _retorno_de_pilha(eh_retorno_de_pilha) {};
    
    bool eh_inicial() { return _inicial; };
    bool eh_final() { return _final; };
    bool eh_retorno_de_pilha() { return _retorno_de_pilha; };

  private:
    bool _inicial;
    bool _final;
    bool _retorno_de_pilha;
};

#endif