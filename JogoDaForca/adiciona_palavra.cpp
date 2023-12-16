#include <iostream>
#include "le_arquivo.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

void adiciona_palavra(){
    // Método que salva palavra do usuário no banco de palavras
    std::cout << "Digite a nova palavra, usando letras maiúsculas. " << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;

    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}