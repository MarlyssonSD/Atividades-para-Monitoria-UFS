#include <iostream>
using namespace std;

/*
Em uma loja, é solicitado que utilizando o dia e o horário (horas e minutos) seja identificado quantas pessoas entraram na loja naquele horário e dia definido.
Faça uma matriz utilizando os conceitos de alocação dinâmica que quando informado o dia (segunda = 0, terça = 1...)
juntamente da hora e dos minutos, possamos descobrir quantas pessoas entraram na loja.
Obs: Horas no formato 24h e os minutos vão até 59.
A hora deve estar no formato 24h:
Exemplo: Ao invés de utilizar 6h PM, deve-se utilizar 18h. 

*/

int main()
{
    int **horario = new int *[24];

    for (int i = 0; i < 24; i++)
    {
        horario[i] = new int[60];
    }

}