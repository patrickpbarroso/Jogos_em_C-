#include <string>

extern std::string palavra_secreta;

bool letra_existe(char chute){
    // Método que verifica se a letra chutada existe na palavra secreta
     for(char letra : palavra_secreta){
            if(chute == letra){
                return true;
            }
     }
     return false;
}