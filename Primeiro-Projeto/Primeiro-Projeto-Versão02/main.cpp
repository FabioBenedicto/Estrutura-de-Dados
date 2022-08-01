#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "calc.h"

using namespace std;
//variaveis globais
char pData[256] = "D:\\Users\\Usuario\\pastas\\PD\\SegundoAno\\EstruturadeDados\\C\\Dados\\";
char pAno[5] = "";
char pTurma[11] = "";
char pSerie[2] = "";
char pDisc[11] = "";

int main(int argc, char *argv[])
{
    int opcao = 0;
    int np = 0;

    /*for(np=0; np < argc; np++){
        printf("%d - %s\n",np, argv[np]);
    }*/

    if(argc>0)
        strcpy(pData, argv[1]);

    loadConfig();

    setlocale(LC_ALL, "Portuguese");

    do {
        opcao = menu();
        switch(opcao){
        case 1:
            imprimirBoletim();
            break;
        case 2:
            lancamentos();
            break;
        case 9:
          saveConfig();
            break;
        case 0:{
                printf("Fechando o programa...");
                exit(1);
            }
        }
    } while (1);

    printf("FIM");
    return 0;
}


