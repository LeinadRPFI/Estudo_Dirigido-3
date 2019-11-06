#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include <algorithm>

using namespace std;




    bool repitidos(vector <int> valores, int tamanho, int valor){

        for(int i = 0; i < tamanho; i++){

            if(valores[i] == valor) return true;
        }

        return false;

    }

    void gerador_aleatorio(int quant_dezenas ,int minimo, int limite, int apostas){


        int aux=0;

    for(int j = 0; j < apostas; j++){

        aux++;

        cout << "Gerando os valores.... \n";

        Sleep(1000);


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
        
        sort(begin(numeros), end(numeros));

        cout << "Numeros para a " << aux << "ª aposta : ";

            for(int i = 0; i < quant_dezenas; i++){

                cout << numeros[i] << ", ";

                if(i == 20) cout << endl;

            }

            cout << endl << endl;

            for(int a = 0; a < numeros.size();a++){

                numeros[a] = ' ';
            }

        }
    }

    void mega_sena(int apostas){

        int dezenas;
        double total = 0;

        cout << "===== MEGA-SENA =====" << endl << endl;

        digite_novamente:

        cout << "Voce deve apostar entre 6 e 15 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;


        if(dezenas >= 6 && dezenas <= 15)

        gerador_aleatorio(dezenas, 1, 60, apostas);

        else goto digite_novamente;

        vector <double> valor_aposta {3.50, 24.50 ,98, 294, 735, 1617, 3234, 6006, 10510.50, 17517.50};


        for(int i = 0; i < apostas; i++){

        total = total + valor_aposta[dezenas-6];

        }

        cout << "O preço total das suas apostas é: R$ " << fixed << setprecision(2) << total << endl;

    }

    void quina(int apostas){

        int dezenas;
        double total = 0;

        cout << "===== Quina ===== \n \n";

        digite_novamente:

        cout << "Voce deve apostar entre 5 e 15 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas >= 5 && dezenas <= 15)

        gerador_aleatorio(dezenas, 1 ,80,apostas);

        else goto digite_novamente;

        vector <double> valor_aposta = {1.50 ,9 ,31.50,84 ,189,378 ,693 ,1188 ,1930.50 ,3003 ,4504.50};


        for(int i = 0; i < apostas; i++){

        total = total + valor_aposta[dezenas-5];

        }

        cout << "O preço total das suas apostas é: R$ " << fixed << setprecision(2) << total << endl;


    }

    void lotomania(int apostas){

        int dezenas;

        cout << "===== Lotomania ===== \n \n";

        digite_novamente:

        cout << "Voce deve apostar até no máximo 50 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas > 0 && dezenas <= 50)

        gerador_aleatorio(dezenas, 0 ,99, apostas);

        else goto digite_novamente;


        cout << "O valor total das suas apostas é: R$ " << fixed << setprecision(2) << 1.5 * apostas;



    }

    void lotofacil(int apostas){

        int dezenas;
        double total = 0;

        cout << "===== Lotofácil ===== \n \n";

        digite_novamente:

        cout << "Voce deve apostar entre 15 e 18 dezenas \n";
        cout << "Quantas dezenas desejas apostar? \n";
        cin >> dezenas;

        cout << endl;

        if(dezenas >= 15 && dezenas <= 18)

        gerador_aleatorio(dezenas, 1 ,25, apostas);

        else goto digite_novamente;

        vector <double> valor_aposta {2, 32, 272, 1632};

         for(int i = 0; i < apostas; i++){

        total = total + valor_aposta[dezenas-15];

        }

        cout << "O preço total das suas apostas é: R$ " << fixed << setprecision(2) << total << endl;
    }

    int main (){

        setlocale(LC_ALL,"Portuguese");

        int escolha, dezenas, apostas;

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

        cout << "Quantas apostas desejas fazer? \n";
        cin >> apostas;
        cout << endl;


        switch(escolha) {

            case 1:

                mega_sena(apostas);
                break;

            case 2:

                quina(apostas);
                break;

            case 3:

                lotomania(apostas);
                break;

            case 4:

                lotofacil(apostas);
                break;

        }



        return 0;
    }
