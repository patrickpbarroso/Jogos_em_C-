#include <iostream>
#include <vector>
#include <map>
#include "letra_existe.cpp"

std::vector<char> chutes_errados;
std::map<char, bool> chutou;

void chutar(){
    // Método para receber chutes do usuário e analisar se ele acertou ou não
    std::cout << "Seu chute: ";

        char chute;
        std::cin >> chute;

        chutou[chute] = true;

        // Verifica se o chute existe na palavra secreta
        if(letra_existe(chute)){
            std::cout << "Você acertou! Seu chute está na palavra." << std::endl;
        }
        else{
            std::cout << "Você errou! Seu chute não está na palavra." << std::endl;
            chutes_errados.push_back(chute);
        }
    std::cout << std::endl;
}