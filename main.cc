#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

#include "analisador_lexico/diagrama_de_transicao.h"
#include "analisador_lexico/funcoes_de_transicoes/char.h"
#include "analisador_lexico/funcoes_de_transicoes/digito.h"
#include "analisador_lexico/funcoes_de_transicoes/literal.h"
#include "analisador_lexico/funcoes_de_transicoes/outro.h"
#include "analisador_lexico/estado.h"
#include "analisador_lexico/transicao.h"

int main() {
    std::ifstream inputFile("input.txt");  // Open the file for reading
    std::vector<char> characters;          // Vector to store each character of the file
    char ch;

    // Check if the file is open
    if (inputFile.is_open()) {
        // Read each character from the file and add it to the vector
        while (inputFile.get(ch)) {
            characters.push_back(ch);
        }
        inputFile.close();  // Close the file after reading
    } else {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;  // Return an error code if the file could not be opened
    }

    // Display the contents of the vector (each character)
    for (const auto& c : characters) {
        std::cout << c;  // Print characters without additional formatting
    }

    return 0;
}