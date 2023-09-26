//O desafio consiste no seguinte, adcionar as 3 coisas que estão sendo pedidas e fazer funcionar numa biblioteca. OBS: o limite de clientes deve ser 10.
//Cada cliente possui o campo ID, Nome e Saldo na conta.
//Ao fazer depósito ou saque, deve ser perguntado o ID do cliente que vai fazer essa operação. Caso o cliente não exista, imprima mensagem de erro
//Sugestão: usar um vetor de tamanho 10 para representar a lista e usar o ID -1 como cliente vazio e usar uma struc para armazenar ID, Nome e Saldo na conta.
//A operação de saque deve ter verificação de saldo para impedir sacar mais do que ele tenha imprima algo como (voce e liso!!! não tem x saldo disponivel).
//Atenciosamente qualquer dúvida ou pergunta pode ser solucionada no horário da monitória ou por email: marcossvin.so@gmaill.com
#include <iostream>
#include <string.h>
#include <cstdlib>
//#include "banco.h"
#define max 10
using namespace std;
struct Cadastro{
    int id;
    char nome[60];
    double Saldo;
};

void cadastrarCliente(struct Cadastro *vetor, int indice);
void sacarDinheiro(struct Cadastro *vetor,int numClientes);
void adicionarDinheiro(struct Cadastro *vetor, int numClientes);

int main() {
    
    int tamanho = 10;
    struct Cadastro *cadastros = (struct Cadastro *)calloc(tamanho, sizeof(struct Cadastro));
    int i = 0;
    int opcao;
    do {
        //system("cls"); // Limpa a tela no Windows
        cout << "\nBanco Simulado\n";
        cout << "1. Cadastrar Cliente\n";
        cout << "2. Sacar Dinheiro\n";
        cout << "3. Adicionar Dinheiro\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                if (i==10){
                    cout << "Nao e possivel salvar mais clientes!" << endl;
                }else{
                    cadastrarCliente(cadastros,i);
                    i++;
                }                
                break;
            case 2:
                sacarDinheiro(cadastros,i);
                break;
            case 3:
                adicionarDinheiro(cadastros,i);
                break;
            case 4:
                cout << "Saindo do programa. Obrigado!\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                system("pause");
                break;
        }
        
    } while (opcao != 4);

    return 0;
}

void cadastrarCliente(struct Cadastro *vetor, int indice) {
    printf("Digite o ID do cliente %d: ", indice + 1);
    scanf("%d", &vetor[indice].id);

    printf("Digite o nome do cliente %d: ", indice + 1);
    scanf("%s", vetor[indice].nome);

    printf("Digite o saldo do cliente %d: ", indice + 1);
    scanf("%lf", &vetor[indice].Saldo);
}

void sacarDinheiro(struct Cadastro *vetor, int numClientes){
    int indice,verdd = 1,c=0;
    double saque;
    cout << "Qual o ID do cliente que esta buscando?" << endl;
    cin >> indice;

    for (int i = 0; i < numClientes; i++){
        if (indice == vetor[i].id){
            cout << "Quanto deseja sacar?";
            while (verdd){
                cin >> saque;
                if (saque > vetor[i].Saldo){
                    cout << "Valor e maior que o saldo!" << endl;
                    system("pause");
                }else{
                    verdd = 0;
                }
                vetor[i].Saldo -= saque;
            }
            cout << "Saque atual de " <<vetor[i].nome <<" agora eh " << vetor[i].Saldo << endl;
            system("pause");
            c = 2;   
        }else if(c != 2){
            c = 1;
        }  
    }
    if(c == 1 || numClientes == 0){
        cout << "Cliente nao existe" << endl;
        system("pause");
    }
}

void adicionarDinheiro(struct Cadastro *vetor, int numClientes){
    int indice,c = 0;
    double adcionar;
    cout << "Qual o ID do cliente que esta buscando?" << endl;
    cin >> indice;

    for (int i = 0; i < numClientes; i++){
        if (indice == vetor[i].id){
            cout << "Quanto deseja adcionar?";
            cin >> adcionar;    
            vetor[i].Saldo += adcionar;
            cout << "Saque atual de " <<vetor[i].nome <<" agora eh " << vetor[i].Saldo << endl;   
            system("pause");
            c = 2;
        }else if(c != 2){
            c = 1;
        }
    }
    if(c == 1 || numClientes == 0){
        cout << "Cliente nao existe" << endl;
        system("pause");
    }
}
