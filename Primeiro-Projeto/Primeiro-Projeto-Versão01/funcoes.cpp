#include <stdio.h>
#include <iostream>
#include <conio.h>

int menu()
{
    int op=0;

    do
    {
        system ("cls");
        printf ("1 = Op��o Um\n");
        printf ("2 = Op��o Dois\n");
        printf ("3 = Op��o Tr�s\n");
        printf ("0 = Sair\n");
        /*op=getchar();*/
        scanf ("%d", &op);
        if (op>=0 && op<=3)
        {
            return op;
        }
        else
        {
            printf("Op��o inv�lida, Digite qualquer tecla!\n");
            while (!(_kbhit()));

            }

    }
    while (1);
}

void exec_op1 (int op)
{
    printf ("Executando fun��o %d\n\n", op);
    getche (); // espera o usu�rio pressionar uma tecla
    return;
}
void exec_op2 (int op)
{
    printf ("Executando fun��o %d\n\n", op);
    getche (); // espera o usu�rio pressionar uma tecla
    return;
}

void exec_op3 (int op)
{
    printf ("Executando fun��o %d\n\n", op);
    getche (); // espera o usu�rio pressionar uma tecla
    return;
}

