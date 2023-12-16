#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_chutes_errados.hpp"
#include "imprime_palavra.hpp"
#include "chutar.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "salva_arquivo.hpp"
#include "adiciona_palavra.hpp"

bool nao_acertou();

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