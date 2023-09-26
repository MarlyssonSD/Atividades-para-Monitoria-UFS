#include<iostream>

using namespace std;

struct Cadastro{
    int id;
    char nome[60];
    double Saldo;
};

void cadastrarCliente(struct Cadastro *vetor, int indice);
void sacarDinheiro(struct Cadastro *vetor,int numClientes);
void adicionarDinheiro(struct Cadastro *vetor, int numClientes);

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


