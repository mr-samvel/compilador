#ifndef fabrica_diagrama_de_transicao_h
#define fabrica_diagrama_de_transicao_h

#include "diagrama_de_transicao.h"

class FabricaDiagramaDeTransicao {
  public:
    static DiagramaDeTransicao* get_diagrama_ident();
    static DiagramaDeTransicao* get_diagrama_int();
    static DiagramaDeTransicao* get_diagrama_float();

  private:
    FabricaDiagramaDeTransicao() = delete;  // Previne instanciação, esta é uma classe estática
};

#endif