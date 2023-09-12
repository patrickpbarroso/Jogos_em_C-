#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){
    cout << "************************************" << endl;
    cout << "* Bem vindo ao jogo da advinhação! *" << endl;
    cout << "************************************" << endl;

    cout << "Escolha o nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int max_tentativas;

    if (dificuldade == 'F'){
        max_tentativas = 15;
    }
    else if (dificuldade == 'M'){
        max_tentativas = 10;
    }
    else {
        max_tentativas = 5;
    }

    srand(time(NULL));
    int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= max_tentativas; tentativas++){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual é o seu chute? ";
        cin >> chute; 

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parabéns! Você acertou o número secreto." << endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute foi maior que o número secreto." << endl;
        }
        else {
            cout << "Seu chute foi menor que o número secreto." << endl;
        }
    }      
    
    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Você perdeu! O número secreto era " << NUMERO_SECRETO << ". Tente novamente." << endl;
    }
    else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }
    
}