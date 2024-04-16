#include <iostream>

using namespace std;
// --Parte 1.1
int entrada()
{
    int num;
    cin >> num;
    return num;
}

// --Parte 1.2
int verificaPrimo(int numero)
{
    int ehPrimo = 1;
    if (numero == 1)
    {
        return 0;
    }
    else
    {
        for (int a = 2; a < (numero / 2 + 1); a++)
            if (numero % a == 0)
            {
                ehPrimo = 0;
                break;
            }
        return ehPrimo;
    }
}

int verificaListaPrimos(int tamLista, int lista[])
{
    cout << "\n Verificando numeros" << endl;
    //--Parte 1.4
    int verificador;
    for (int a = 0; a < tamLista; a++)
    {
        verificador = verificaPrimo(lista[a]);
        if (verificador)
            cout << lista[a] << " eh primo\n";
        else
            cout << lista[a] << " nao eh primo\n";
    }
}

// --Parte 2.1
int contaDivisores(int n)
{
    int contagem = 1; // inicia em 1 pois n já é divisível por n e o for não vai até n
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            contagem += 1;
    return contagem;
}

//--Parte 2.2
int armazenaDivisores(int n, int lista[])
{

    int contagem = 1; // inicia em 1 pois n já é divisível por n e o for não vai até n
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
        {
            lista[contagem - 1] = i;
            contagem += 1;
        }
    lista[contagem - 1] = n; // adiciona o próprio n na lista
    return contagem;
}

int main()
{

    int tamLista = 10;
    int lista[tamLista] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // --Parte 1.3
    // for (int a = 0; a < tamLista; a++)
    //     lista[a] = entrada();
    // verificaListaPrimos(tamLista, lista);

    int n = 30, tamNovalista = contaDivisores(n);
    int novaLista[tamNovalista];

    // armazenaDivisores(n, novaLista);

    // for (int a = 0; a < tamNovalista; a++)
    //     cout << novaLista[a] << endl;

    // armazenaDivisores(30, novaLista);

    // verificaListaPrimos(tamNovalista, novaLista);

    return 0;
}