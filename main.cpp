#include <iostream>
#include <string.h>
#include <cstdlib>
#include "banco.h"
using namespace std;

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

