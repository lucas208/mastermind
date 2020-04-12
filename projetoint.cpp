#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;

int main ()
{
    int opcao,nivel;
    char nome[101];
    cout << "Insira seu nome: "<< endl;
    cin.getline(nome,100);
    system("cls");
    cout << endl;

    for(int i =0; nome[i]!='\0'; i++)
    {
        cout<<nome[i];
    }
    cout << ", selecione a opcao desejada:" << endl;
    cout << endl;

    cout << "OPCOES:" << endl;
    cout << "1 para instrucoes " << endl;
    cout << "2 para jogar " << endl;
    cout << "3 para sair " << endl;
    cout << "4 para modo multiplayer" << endl;
    cin >> opcao;
    while(opcao!=3)
    {
        if(opcao == 1)
        {
            system("cls");
            for(int i =0; nome[i]!='\0'; i++)
            {
                cout<<nome[i];
            }
            cout <<", leia atentamente "<< endl;
            cout << "Instrucoes" << endl;
            cout << "No jogo voce tenta advinhar uma senha gerada pelo computador " << endl;
            cout << "essa senha eh composta por  digitos que podem" << endl;
            cout << "assumir os valores de um intervalo numerico especifico, por exemplo:" << endl;
            cout << "numeros de 1 a 6. A cada tentativa a qualidade do seu palpite eh mostrada" << endl;
            cout << "atraves de pinos brancos [1] e pretos [2], brancos para numero certo na posicao certa";
            cout << " pretos para numero certo na posicao errada, 0 caso contrario. "<< endl;
            cout << endl;
            cout << "2 para jogar"<<endl;
            cout << "3 para sair"<<endl;
            cout <<"4 para modo multiplayer "<< endl;
            cin >> opcao;
        }

        else if(opcao == 2)
        {
            system("cls");

            for(int i =0; nome[i]!='\0'; i++)
            {
                cout<<nome[i];
            }
            cout <<", selecione o nivel de dificuldade" << endl;
            cout << endl;
            cout << "1 - para nivel 1 " << endl;
            cout << "2 - para nivel 2 " << endl;
            cout << "3 - para nivel 3 " << endl;
            cin >> nivel;
inicio:
            if (nivel == 1)
            {
                system("cls");
                srand(time(NULL)); // Função que "zera" os valores randomicos para uma sequencia diferente
                int senha[4];
                int palpite[4];
                int resultado[4];
                int branco = 0;
                int preto = 0;
                int pontuacao;

                cout << "Senha gerada, insira 4 numeros de 1 a 6 " << endl;

                for(int i =0; i<4; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<4; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%6)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
               // for(int i =0; i<4; i++)
              //  {
               //     cout << senha[i] << " ";
             //   }
                cout << endl;

                for(int k=0; k<10; k++)
                {
                    cout << endl;

                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<4; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>6)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<4; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<4; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<4; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao = 100 -10*k;
                    if(branco == 4)
                    {
                        break;
                    }
                    for(int i =0; i<4; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == 4)
                {
                    for(int i =0; i<4; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", voce venceu! " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<4; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << ", voce perdeu =(" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<4; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao = 0;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                cout <<endl;
                for(int i =0; nome[i]!='\0'; i++)
                {
                    cout<<nome[i];
                }
                cout <<", escolha por favor: "<< endl;
                cout << "1 - para instrucoes"<< endl;
                cout <<" 2 - para jogar novamente "<< endl;
                cout <<" 3 - para sair"<< endl;
                cout <<" 4 - para modo multiplayer "<< endl;
                cin >>opcao;

            }
            else if (nivel == 2)
            {
                system("cls");
                srand(time(NULL)); // Função que "zera" os valores randomicos para uma sequencia diferente
                int x = 5;
                int c = 7;
                int t = 12;
                int senha[x];
                int palpite[x];
                int resultado[x];
                int branco = 0;
                int preto = 0;
                int pontuacao;



                cout << "Senha gerada, insira 5 numeros de 1 a 7 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>7)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", voce venceu! " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << ", voce perdeu =(" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao = 0;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                cout <<endl;
                for(int i =0; nome[i]!='\0'; i++)
                {
                    cout<<nome[i];
                }
                cout <<", escolha por favor: "<< endl;
                cout << "1 - para instrucoes"<< endl;
                cout <<" 2 - para jogar novamente "<< endl;
                cout <<" 3 - para sair"<< endl;
                cout <<" 4 - para modo multiplayer "<< endl;
                cin >>opcao;

            }
            else if (nivel == 3)
            {
                system("cls");
                srand(time(NULL)); // Função que "zera" os valores randomicos para uma sequencia diferente
                int x = 6;
                int c = 8;
                int t = 14;
                int senha[x];
                int palpite[x];
                int resultado[x];
                int branco = 0;
                int preto = 0;
                int pontuacao;

                cout << "Senha gerada, insira 6 numeros de 1 a 8 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>8)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", voce venceu! " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << ", voce perdeu =(" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao = 0;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                cout <<endl;
                for(int i =0; nome[i]!='\0'; i++)
                {
                    cout<<nome[i];
                }
                cout <<", escolha por favor: "<< endl;
                cout << "1 - para instrucoes"<< endl;
                cout <<" 2 - para jogar novamente "<< endl;
                cout <<" 3 - para sair"<< endl;
                cout <<" 4 - para modo multiplayer "<< endl;
                cin >>opcao;

            }
            else
            {
                cout << "Nivel invalido, tente novamente" << endl;
                cin >> nivel;
                goto inicio;
            }

        }
        else if(opcao == 4)
        {
            int nivel2;
            system("cls");
            cin.ignore();
            char nome2[101];
            cout << "Insira o nome do segundo jogador: "<< endl;
            cin.getline(nome2,100);
            system("cls");
            for(int i =0; nome[i]!='\0'; i++)
            {
                cout<<nome[i];
            }
            cout << " e ";
            for(int i =0; nome2[i]!='\0'; i++)
            {
                cout<<nome2[i];
            }
            cout <<", selecionem o nivel de dificuldade" << endl;
            cout << endl;
            cout << "1 - para nivel 1 " << endl;
            cout << "2 - para nivel 2 " << endl;
            cout << "3 - para nivel 3 " << endl;
            cin >> nivel2;
inicio2:
            if(nivel2 == 1)
            {
                system("cls");
                srand(time(NULL)); // Função que "zera" os valores randomicos para uma sequencia diferente
                int x = 4;
                int c = 6;
                int t = 10;
                int senha[x];
                int palpite[x];
                int resultado[x];
                int branco = 0;
                int preto = 0;
                int pontuacao;
                int pontuacao2;



                cout << "Senha gerada, insira 4 numeros de 1 a 6 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>6)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", voce acertou a senha " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << ", infelizmente voce nao acertou a senha" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao = 0;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                cout <<"Agora eh a vez do jogador 2 " << endl;
                system("pause");
                system("cls");
                branco = 0; //zerando os contadores dos pinos
                preto = 0;
                cout << "Senha gerada, insira 4 numeros de 1 a 6 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>6)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao2 = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout<<", voce acertou a senha " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao2 << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout << ", infelizmente voce nao acertou a senha" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao2 = 0;
                    cout << "Pontuacao = " << pontuacao2 << endl;

                }
                cout << endl;
                if(pontuacao > pontuacao2)
                {
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout <<" ganhou com um total de "<< pontuacao <<" pontos"<< endl;
                }
                if(pontuacao2 > pontuacao)
                {
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout <<" ganhou com um total de "<< pontuacao2 <<" pontos"<< endl;
                }
                if(pontuacao == pontuacao2)
                {
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << " e ";
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout <<" empataram com um total de "<< pontuacao <<" pontos"<< endl;
                }
                cout << endl;
                for(int i =0; nome[i]!='\0'; i++)
                {
                    cout<<nome[i];
                }
                cout << " e ";
                for(int i =0; nome2[i]!='\0'; i++)
                {
                    cout<<nome2[i];
                }
                cout <<", selecionem o que fazer agora:" << endl;
                cout <<endl;
                cout << "1 - para instrucoes"<< endl;
                cout << "2 - para jogar single player" << endl;
                cout << "3 - para sair" << endl;
                cout << "4 - para jogar multiplayer novamente " << endl;
                cin >> opcao;
            }
            else if(nivel2 == 2)
            {
                system("cls");
                srand(time(NULL)); // Função que "zera" os valores randomicos para uma sequencia diferente
                int x = 5;
                int c = 7;
                int t = 12;
                int senha[x];
                int palpite[x];
                int resultado[x];
                int branco = 0;
                int preto = 0;
                int pontuacao;
                int pontuacao2;



                cout << "Senha gerada, insira 5 numeros de 1 a 7 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>7)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", voce acertou a senha " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << ", infelizmente voce nao acertou a senha" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao = 0;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                cout <<"Agora eh a vez do jogador 2 " << endl;
                system("pause");
                system("cls");
                branco = 0; //zerando os contadores dos pinos
                preto = 0;
                cout << "Senha gerada, insira 5 numeros de 1 a 7 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>7)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao2 = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout<<", voce acertou a senha " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao2 << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout << ", infelizmente voce nao acertou a senha" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao2 = 0;
                    cout << "Pontuacao = " << pontuacao2 << endl;

                }
                cout << endl;
                if(pontuacao > pontuacao2)
                {
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout <<" ganhou com um total de "<< pontuacao <<" pontos"<< endl;
                }
                if(pontuacao2 > pontuacao)
                {
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout <<" ganhou com um total de "<< pontuacao2 <<" pontos"<< endl;
                }
                if(pontuacao == pontuacao2)
                {
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << " e ";
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout <<" empataram com um total de "<< pontuacao <<" pontos"<< endl;
                }
                cout << endl;
                for(int i =0; nome[i]!='\0'; i++)
                {
                    cout<<nome[i];
                }
                cout << " e ";
                for(int i =0; nome2[i]!='\0'; i++)
                {
                    cout<<nome2[i];
                }
                cout <<", selecionem o que fazer agora:" << endl;
                cout <<endl;
                cout << "1 - para instrucoes"<< endl;
                cout << "2 - para jogar single player" << endl;
                cout << "3 - para sair" << endl;
                cout << "4 - para jogar multiplayer novamente " << endl;
                cin >> opcao;
            }
            else if(nivel2 == 3)
            {
                system("cls");
                srand(time(NULL)); // Função que "zera" os valores randomicos para uma sequencia diferente
                int x = 6;
                int c = 8;
                int t = 14;
                int senha[x];
                int palpite[x];
                int resultado[x];
                int branco = 0;
                int preto = 0;
                int pontuacao;
                int pontuacao2;



                cout << "Senha gerada, insira 6 numeros de 1 a 8 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>8)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout<<", voce acertou a senha " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << ", infelizmente voce nao acertou a senha" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao = 0;
                    cout << "Pontuacao = " << pontuacao << endl;
                }
                cout <<"Agora eh a vez do jogador 2 " << endl;
                system("pause");
                system("cls");
                branco = 0; //zerando os contadores dos pinos
                preto = 0;
                cout << "Senha gerada, insira 5 numeros de 1 a 8 " << endl;

                for(int i =0; i<x; i++)   // preenchendo o vetor resultado com 0
                {
                    resultado [i] = 0;
                }

                for(int i=0; i<x; i++)              // gerando a senha aleatória
                {
                    senha[i] = (rand()%c)+1;
                    for(int j=0; j<i; j++)
                    {
                        if(senha[i]==senha[j])
                        {
                            --i;
                        }

                    }
                }
                //for(int i =0; i<x; i++)
                //{
                //    cout << senha[i] << " ";
                //}
                cout << endl;

                for(int k=0; k<t; k++)
                {
                    cout << endl;

                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout<<", digite o seu "<< k+1 <<" palpite: "<< endl;

                    for(int i =0; i<x; i++)               //lendo o palpite do usuário
                    {
                        cin >> palpite[i];
                        while((palpite[i]<1)||(palpite[i]>8)){
                            cout << "Numero fora do intervalo, tente novamente"<< endl;
                            cin>>palpite[i];
                        }
                    }
                    for(int i=0; i<x; i++)                  // contando quantos pinos brancos e pretos teremos
                    {
                        if(senha[i] == palpite[i])
                            branco = branco +1;
                        else
                        {
                            for(int j=0; j<x; j++)
                            {
                                if(senha[i]== palpite[j])
                                    preto = preto +1;
                            }
                        }


                    }
                    cout << endl;
                    cout << "Branco [1] = " << branco << endl;
                    cout << "Preto [2] = " << preto << endl;
                    cout << endl;
                    for(int i=0; i<branco; i++)           // preenchendo o vetor resultado
                    {
                        resultado[i] = 1;
                    }
                    for(int i = 0; i<x; i++)
                    {
                        if(resultado[i]!=1)
                        {
                            while(preto>0)
                            {
                                resultado[i] = 2;
                                ++i;
                                --preto;
                            }
                        }
                    }
                    pontuacao2 = 10*t -10*k;
                    if(branco == x)
                    {
                        break;
                    }
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    preto = 0; // zerando os contadores branco e preto
                    branco = 0;
                }
                if(branco == x)
                {
                    for(int i =0; i<x; i++)             // imprimindo o vetor resultado e zerando esse vetor
                    {
                        cout << resultado[i] << " ";
                        resultado[i] = 0;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "Parabens ";
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout<<", voce acertou a senha " << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    cout << "Pontuacao = " << pontuacao2 << endl;
                }
                else
                {
                    cout << endl;
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout << ", infelizmente voce nao acertou a senha" << endl;
                    cout << endl;
                    cout << "A senha era: ";
                    for(int i =0; i<x; i++)
                    {
                        cout << senha[i] << " ";
                    }
                    cout << endl;
                    pontuacao2 = 0;
                    cout << "Pontuacao = " << pontuacao2 << endl;

                }
                cout << endl;
                if(pontuacao > pontuacao2)
                {
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout <<" ganhou com um total de "<< pontuacao <<" pontos"<< endl;
                }
                if(pontuacao2 > pontuacao)
                {
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout <<" ganhou com um total de "<< pontuacao2 <<" pontos"<< endl;
                }
                if(pontuacao == pontuacao2)
                {
                    for(int i =0; nome[i]!='\0'; i++)
                    {
                        cout<<nome[i];
                    }
                    cout << " e ";
                    for(int i =0; nome2[i]!='\0'; i++)
                    {
                        cout<<nome2[i];
                    }
                    cout <<" empataram com um total de "<< pontuacao <<" pontos"<< endl;
                }
                cout << endl;
                for(int i =0; nome[i]!='\0'; i++)
                {
                    cout<<nome[i];
                }
                cout << " e ";
                for(int i =0; nome2[i]!='\0'; i++)
                {
                    cout<<nome2[i];
                }
                cout <<", selecionem o que fazer agora:" << endl;
                cout <<endl;
                cout << "1 - para instrucoes"<< endl;
                cout << "2 - para jogar single player" << endl;
                cout << "3 - para sair" << endl;
                cout << "4 - para jogar multiplayer novamente " << endl;
                cin >> opcao;
            }
            else
            {
                cout << "Nivel invalido, tente novamente" << endl;
                cin >> nivel2;
                goto inicio2;
            }

        }
        else
        {
            cout << "Opcao invalida, tente novamente" << endl;
            cin >> opcao;
        }

    }
    cout << endl;
    cout<< "Fim do programa" << endl;
}
