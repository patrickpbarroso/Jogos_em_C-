#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute){
    // Método que verifica se a letra chutada existe na palavra secreta
     for(char letra : palavra_secreta){
            if(chute == letra){
                return true;
            }
     }
     return false;
}

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

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    // Método que imprime cabeçalho do jogo
    cout << "********************" << endl;
    cout << "** Jogo da Forca ***" << endl;
    cout << "********************" << endl;
    cout << endl;

}

void imprime_chutes_errados(){
    // Método que imprime chutes errados
    cout << "Chutes errados: ";
        for(char letra: chutes_errados){
            cout << letra << " ";
        }
        cout << endl;
}

void imprime_palavra(){
    // Método para imprimir palavras com chutes certos e espaços
    for(char letra: palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void chutar(){
    // Método para receber chutes do usuário e analisar se ele acertou ou não
    cout << "Seu chute: ";

        char chute;
        cin >> chute;

        chutou[chute] = true;

        // Verifica se o chute existe na palavra secreta
        if(letra_existe(chute)){
            cout << "Você acertou! Seu chute está na palavra." << endl;
        }
        else{
            cout << "Você errou! Seu chute não está na palavra." << endl;
            chutes_errados.push_back(chute);
        }
    cout << endl;
}

vector<string> le_arquivo(){
    // Método para ler palavras do arquivo txt
    ifstream arquivo;
    arquivo.open("palavras.txt");

    // Verifica se o arquivo está aberto e realiza a leitura
    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_do_arquivo;

        for(int i=0;i<quantidade_palavras;i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }

        arquivo.close();
        return palavras_do_arquivo;
    }
    else
    {
        cout << "Não foi possível acessar o banco de palavras. " << endl;
        exit(0);
    }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

int main(){
    imprime_cabecalho();

    // Lê banco de palavras do jogo
    le_arquivo();

    // Sorteia palavra escolhida
    sorteia_palavra();
    // O jogo se repete enquanto o usuário não acertar ou perder enforcado
    while(nao_acertou() && nao_enforcou()){
        // Mostra chutes errados, palavra com chutes certos e espaços e recebe chutes
        imprime_chutes_errados();

        imprime_palavra();

        chutar();
    }

    // Usuário venceu o jogo: Acertou a palavra secreta
    if (!nao_acertou()){
        cout << "Parabéns! Você ganhou. A palavra secreta era " << palavra_secreta 
        << endl;
    }
    // Usuário perdeu o jogo: Errou a palavra secreta
    else
    {
        cout << "Você perdeu e foi terrivelmente enforcado. A palavra secreta era "
        << palavra_secreta << endl;
    }
}