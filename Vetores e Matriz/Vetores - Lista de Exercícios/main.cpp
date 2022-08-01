//F�bio Henrique Benedicto 2�MINFD 200126 20/05
#include <iostream>
#include "vetores.h"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int vetor1[] = {1, 2, 3, 4, 5};
    int vetor2[] = {5, 10, 5, 10, 5};

    printf("Primeiro vetor: ");
    impVetint(vetor1, 5);
    printf("Segundo vetor: ");
    impVetint(vetor2, 5);

    printf("\n");

    printf("Escalar: %d", escalar(vetor1, vetor2, 5));

    printf("\n\n");

    if(todosDiferentes(vetor1, 5) == 1){
        printf("Todos os valores do primeiro vetor s�o diferentes");
    } else {
        printf("Todos os valores do primeiro vetor n�o s�o diferentes");
    }

    printf("\n");

    if(todosDiferentes(vetor2, 5) == 1){
        printf("Todos os valores do segundo vetor s�o diferentes");
    } else {
        printf("Todos os valores do segundo vetor n�o s�o diferentes");
    }

    printf("\n");
    printf("\n");

    rotaciona(vetor1, 5);
    rotaciona(vetor2, 5);
    printf("Primeiro vetor: ");
    impVetint(vetor1, 5);
    printf("Primeiro vetor: ");
    impVetint(vetor2, 5);

    printf("\n");

    printf("O primeiro vetor possui %d valores entre 1 e 5", contaValores(vetor1, 5, 1, 5));
    printf("\nO segundo vetor possui %d valores entre 1 e 10", contaValores(vetor2, 5, 1, 10));

    printf("\n");
    printf("\n");

    printf("O menor elemento do primeiro vetor � %d elemento", menorElemento(vetor1, 5));
    printf("\nO menor elemento do segundo vetor � %d elemento", menorElemento(vetor2, 5));

    printf("\n");
    printf("\n");

    printf("O maior elemento do primeiro vetor � %d", maiorElemento(vetor1, 5));
    printf("\nO maior elemento do segundo vetor � %d", maiorElemento(vetor2, 5));

    printf("\n");
    printf("\n");

    printf("%d elementos do segundo vetor est�o contidos no primeiro", contidos(vetor1, 5, vetor2, 5));


    return 0;
}
