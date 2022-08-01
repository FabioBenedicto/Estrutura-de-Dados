#include <iostream>
#include "funcoes.h"
#include <locale.h>
#include <stdlib.h>
#include "calc.h"

using namespace std;

int main()
{
    int opcao = 0;
    setlocale (LC_ALL, "Portuguese");

    do
    {
        opcao=menu();
        printf ("Opção = %d\n\n", opcao);

        switch (opcao)
        {

        case 1:
        {
            exec_op1(1);
            break;
        }
        case 2:
        {
            exec_op2(2);
            break;
        }
        case 3:
        {
            exec_op3(3);
            break;
        }
        case 0:
        {
            printf ("Saindo...\n");
            exit(1);
        }

        }
    }
    while(1);

    printf ("F I M\n");

    return 0;
}
