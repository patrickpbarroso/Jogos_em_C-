#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.cpp"
#include "letra_existe.cpp"
#include "nao_enforcou.cpp"
#include "imprime_cabecalho.cpp"
#include "imprime_chutes_errados.cpp"
#include "imprime_palavra.cpp"
#include "chutar.cpp"
#include "le_arquivo.cpp"
#include "sorteia_palavra.cpp"
#include "salva_arquivo.cpp"
#include "adiciona_palavra.cpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

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

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) " << endl;
        char resposta;
        cin >> resposta;
        if (resposta == 'S'){
            adiciona_palavra();
        }
    }
    // Usuário perdeu o jogo: Errou a palavra secreta
    else
    {
        cout << "Você perdeu e foi terrivelmente enforcado. A palavra secreta era "
        << palavra_secreta << endl;
    }
}