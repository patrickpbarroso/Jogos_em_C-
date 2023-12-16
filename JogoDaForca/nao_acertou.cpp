#include <string>
#include <map>

    // Método para imprimir palavras com chutes certos e espaços
extern std::string palavra_secreta;
extern std::map<char, bool> chutou;

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