#include <vector>
#include <iostream>

extern std::vector<char> chutes_errados;

void imprime_chutes_errados(){
    // Método que imprime chutes errados
    std::cout << "Chutes errados: ";
        for(char letra: chutes_errados){
            std::cout << letra << " ";
        }
        std::cout << std::endl;
}