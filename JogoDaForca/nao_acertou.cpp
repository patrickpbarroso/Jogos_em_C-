#include <string>
#include <map>

std::string palavra_secreta;
std::map<char, bool> chutou;

bool nao_acertou(){
    // Método que verifica se a pessoa não acertou alguma letra
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    // Todas as letras foram acertadas
    return false;
}