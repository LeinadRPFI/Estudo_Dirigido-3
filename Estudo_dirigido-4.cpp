#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <iomanip>

using namespace std;




    bool repitidos(vector <int> valores, int tamanho, int valor){

        for(int i = 0; i < tamanho; i++){

            if(valores[i] == valor) return true;
        }

        return false;

    }

    void gerador_aleatorio(int quant_dezenas ,int minimo, int limite){

        srand(time(NULL));

        int ax;
        vector <int> numeros;

        for(int i = 0; i < quant_dezenas; i++){

            denovo:

            ax = minimo + rand() % limite;

            if(!repitidos(numeros, i, ax)){

                    numeros.push_back(ax);
               }
            else goto denovo;
        }

        cout << "Numeros para a aposta : ";

            for(int i = 0; i < quant_dezenas; i++){

                cout << numeros[i] << ", ";

            }

            cout << endl << endl;

    }

    void mega_sena(){

        int dezenas;

        cout << "===== MEGA-SENA =====" << endl << endl;

        digite_novamente:

        cout << "Voce deve apostar entre 6 e 15 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas >= 6 && dezenas <= 15)

        gerador_aleatorio(dezenas, 1, 60);

        else goto digite_novamente;

        vector <string> valor_aposta {"3,50", "24,50","98,00","294,00","735,00","1.617,00","3.234,00","6.006,00","10.510,50","17.517,50"};

        cout << "O valor da sua aposta é: R$ " << valor_aposta[dezenas-6];

    }

    void quina(){

        int dezenas;

        cout << "===== Quina ===== \n \n";

        digite_novamente:

        cout << "Voce deve apostar entre 5 e 15 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas >= 5 && dezenas <= 15)

        gerador_aleatorio(dezenas, 1 ,80);

        else goto digite_novamente;

        vector <string> valor_aposta {"1,50","9,00","31,50","84,00","189,00","378,00","693,00","1.188,00","1.930,50","3.003,00","4.504,50"};

        cout << "O valor da sua aposta é: R$ " << valor_aposta[dezenas-5];


    }

    void lotomania(){

        int dezenas;

        cout << "===== Lotomania ===== \n \n";

        digite_novamente:

        cout << "Voce deve apostar até no máximo 50 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas > 0 && dezenas <= 50)

        gerador_aleatorio(dezenas, 0 ,99);

        else goto digite_novamente;


        cout << "O valor da sua aposta é: R$ 1,50";

    }

    void lotofacil(){

        int dezenas;

        cout << "===== Lotofácil ===== \n \n";

        digite_novamente:

        cout << "Voce deve apostar entre 15 e 18 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas >= 15 && dezenas <= 18)

        gerador_aleatorio(dezenas, 1 ,25);

        else goto digite_novamente;

        vector <string> valor_aposta {"2,00","32,00","272,00","1.632,00"};

        cout << "O valor da sua aposta é: R$ " << valor_aposta[dezenas-15];
    }

    int main (){

        setlocale(LC_ALL,"Portuguese");

        int escolha, dezenas;

        cout << endl;
        cout << "       ========== Seja bem vindo ao gerador de apostas 4.0 ========== \n \n";

        cout << "Olá usuário, você poderá jogar nos seguintes jogos: \n \n";

        cout << " 1. Mega-Sena \n";
        cout << " 2. Quina \n";
        cout << " 3. Lotomania \n";
        cout << " 4. Lotofácil \n";

        cout << endl;

        cout << "Digite o número correspondente ao jogo que desejas jogar: ";
        cin >> escolha;
        cout << endl;

        switch(escolha) {

            case 1:

                mega_sena();
                break;

            case 2:

                quina();
                break;

            case 3:

                lotomania();
                break;

            case 4:

                lotofacil();
                break;

        }



        return 0;
    }
