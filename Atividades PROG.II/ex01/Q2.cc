#include <iostream>

using namespace std;

void desenhaTrianguloLateral(int n)
{
    for (int a = 0; a < n; a++)
    {

        for (int b = 0; b <= a; b++)
        {
            cout << '*';
        }
        cout << endl;
    }

    for (int a = 0; a < n; a++)
    {

        for (int b = n - 1; b > a; b--)
        {
            cout << '*';
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    cin >> n;
    desenhaTrianguloLateral(n);
}