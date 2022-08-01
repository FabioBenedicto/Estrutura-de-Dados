#include <stdio.h>
#include <iostream>
#include <conio.h>

int menu()
{
    int op=0;

    do
    {
        system ("cls");
        printf ("1 = Opção Um\n");
        printf ("2 = Opção Dois\n");
        printf ("3 = Opção Três\n");
        printf ("0 = Sair\n");
        /*op=getchar();*/
        scanf ("%d", &op);
        if (op>=0 && op<=3)
        {
            return op;
        }
        else
        {
            printf("Opção inválida, Digite qualquer tecla!\n");
            while (!(_kbhit()));

            }

    }
    while (1);
}

void exec_op1 (int op)
{
    printf ("Executando função %d\n\n", op);
    getche (); // espera o usuário pressionar uma tecla
    return;
}
void exec_op2 (int op)
{
    printf ("Executando função %d\n\n", op);
    getche (); // espera o usuário pressionar uma tecla
    return;
}

void exec_op3 (int op)
{
    printf ("Executando função %d\n\n", op);
    getche (); // espera o usuário pressionar uma tecla
    return;
}

