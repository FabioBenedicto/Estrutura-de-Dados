//Fábio Henrique Benedicto 2ºMINFD 200126 07/10/2021
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "pilha.h"

using namespace std;

int main()
{
    Pilha * p = cria();
    int valor = MIN;
    int tecla = 0;

    while((tecla = lerTecla()) != kbESC)
    {
        if(tecla==kbCIMA)
        {
            if(valor >= MIN && valor<=MAX)
            {
                push(p, valor++);
            }
        }
        else if(tecla == kbBAIXO)
        {
            pop(p);
            if(vazia(p))
                valor = MIN;
            else
                valor = lerTopo(p);
        }
        system("cls");
        imprime(p);
    };
    return 0;
}
