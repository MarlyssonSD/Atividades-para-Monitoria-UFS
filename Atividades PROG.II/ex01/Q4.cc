#include <iostream>

using namespace std;

float entrada()
{
    float num;
    cin >> num;
    return num;
}

float calcula(float notas[3], char escolha)
{
    float media = 0;

    if (toupper(escolha) == 'A')
    {
        media = (notas[0] + notas[1] + notas[2]) / 3;
    }
    else if (toupper(escolha) == 'P')
    {
        // Pesos 5, 3 e 2
        media = (notas[0] * 5 + notas[1] * 3 + notas[2] * 2) / (5 + 3 + 2);
    }
    return media;
}

int main()
{
    float notas[3];
    cout << "digite 3 notas:\n";
    for (int a = 0; a < 3; a++)
    {
        notas[a] = entrada();
    }

    char escolha;
    cin >> escolha;
    float resultado = calcula(notas, escolha);
    if (resultado)
        printf("A media eh igual a %.2f", resultado);
}