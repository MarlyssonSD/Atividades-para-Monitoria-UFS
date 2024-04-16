#include <iostream>
#include <string.h>

using namespace std;

struct habitante
{
    char sexo;
    string cor_do_olho;
    string cor_do_cabelo;
    int idade;
};

void coletaInfoHab(habitante &pessoa)
{
    cout << "Qual o sexo? ";
    cin >> pessoa.sexo;
    cout << "Qual a cor do olho? ";
    cin >> pessoa.cor_do_olho;
    cout << "Qual a cor do cabelo? ";
    cin >> pessoa.cor_do_cabelo;
    cout << "Qual a idade? ";
    cin >> pessoa.idade;
}

float mediaIdadeCastanhoPreto(habitante pessoas[], int quantidade)
{
    int contador = 0, idades_somadas = 0;

    for (int x = 0; x < quantidade; x++)
    {
        if (pessoas[x].cor_do_olho == "castanho" && pessoas[x].cor_do_cabelo == "preto")
        {
            contador += 1;
            idades_somadas += pessoas[x].idade;
        }
    }

    return (idades_somadas / contador);
}
int maiorIdade(habitante pessoas[], int quantidade)
{
    int maior_idade = 0;

    for (int x = 0; x < quantidade; x++)
    {
        if (pessoas[x].idade > maior_idade)
            maior_idade = pessoas[x].idade;
    }
    return maior_idade;
}

int mulheres18_35_azul_loiro(habitante pessoas[], int quantidade)
{
    int quant = 0;
    for (int x = 0; x < quantidade; x++)
    {
        if (tolower(pessoas[x].sexo) == 'f' && pessoas[x].idade >= 18 && pessoas[x].idade <= 25 && pessoas[x].cor_do_olho == "azul" && pessoas[x].cor_do_cabelo == "louro")
        {
            quant += 1;
        }
    }

    return quant;
}

int main()
{
    int quant_hab = 4;
    habitante Hab[quant_hab];
    for (int a = 0; a < quant_hab; a++)
    {
        coletaInfoHab(Hab[a]);
    }

    // cout << mediaIdadeCastanhoPreto(Hab, quant_hab);
    // cout << maiorIdade(Hab, quant_hab);
    cout << mulheres18_35_azul_loiro(Hab, quant_hab);

    return 0;
}