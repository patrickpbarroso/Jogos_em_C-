#include <vector>
#include <string>
#include "le_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra(){
    // Método que sorteia palavra secreta para o jogo
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}