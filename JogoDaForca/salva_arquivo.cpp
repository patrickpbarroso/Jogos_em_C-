#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void salva_arquivo(std::vector<std::string> nova_lista_de_palavras){
    // Método que salva arquivo com palavra nova
    std::ofstream arquivo;
    arquivo.open("palavras.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista_de_palavras.size();

        for(std::string palavra: nova_lista_de_palavras){
            arquivo << palavra << std::endl;
        }

        arquivo.close();
    }
    else
    {
        std::cout << "Não foi possível acessar o banco de palavras. " << std::endl;
        exit(0);
    }
}