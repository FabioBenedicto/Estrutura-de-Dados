/* Fábio Henrique Benedicto 2ºMINFD 200126 16/05 */

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


using namespace std;
//variaveis globais
char pData[256]="C:\\Estrututura-de-Dados\\dados\\"; //path dados
char pAno[5]="2021";
char pTurma[11]="infd";
char pSerie[2]="2";
char pDisc[11]="ed";

//vetores globais
char vRa[40][7];
float vNS1[40];
float vNS2[40];
float vFS1[40];
float vFS2[40];
int nEl=0;

int main(int argc, char *argv[])
{
    int opcao = 0;
    int np=0;

    /*for(np=0; np < argc; np++){
        printf("%d - %s\n",np, argv[np]);
    }*/

    if (argc>0) //Verifica se foi passado parâmetros pela linha de comando
        strcpy(pData, argv[1]);

    loadConfig(); //Configura arquivo cfg

    setlocale (LC_ALL, "Portuguese");

    do
    {
        opcao=menu();
        printf ("\nOpção = %d\n\n", opcao);

        switch (opcao)
        {

        case 1:
        {
            imprimirBoletimVector();
            break;
        }
        case 2:
        {
            lancamentosVector();
            break;
        }
        case 9:
        {
            saveConfig();
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
