//Fábio Henrique Benedicto 2ºMINFD 200126 12/08
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

float dados[10][3]
{
    {0, 0.9, 9.8},
    {9.3, 3, 6},
    {5.2, 6.4, 9.4},
    {7.4, 6.4, 9.4},
    {0.8, 0.8, 3.8},
    {9.4, 8.4, 2},
    {3.2, 2.2, 5.2},
    {1.8, 6.9, 9.9},
    {10, 8.8, 2.1},
    {5.4, 4.4, 5.1}
};

void imprDados(float m[10][3])
{
    for (int a=0; a<10; a++)
    {
        for (int b=0; b<3; b++)
        {
            printf("%5.1f |", m[a][b] );
        }
        printf("\n");
    }
}

void imprFaixas(float **fx, int l, int c)
{
    printf(".------------.------.------.\n");
    printf("|   Faixas   | F.A. | FR(%)|\n");
    printf(".------------.------.------.\n");

    for (int a=0; a<l; a++)
    {
        for (int b=0; b<c; b++)
        {
            printf("%5.2f |", fx[a][b]);
        }
        printf("\n");
    }
}

float menorValor(float m[10][3])
{
    float menor;
    for (int a=0; a<10; a++)
    {
        for (int b=0; b<3; b++)
        {
            if (m[a][b] < menor)
                menor = m[a][b];
        }
    }
    return menor;
}

float maiorValor(float m[10][3])
{
    float maior;
    for (int a=0; a<10; a++)
    {
        for (int b=0; b<3; b++)
        {
            if (m[a][b] > maior)
                maior = m[a][b];
        }
    }
    return maior;
}

float mediaValores(float m[10][3])
{
    float soma=0;
    int nEl=0;
    for (int a=0; a<10; a++)
    {
        for (int b=0; b<3; b++)
        {
            soma+=m[a][b];
            nEl++;
        }
    }
    return (soma/nEl);
}

float **geraFaixas(float m[10][3], int nFaixas)
{
    float **fxs;
    int linhas=0, l=0, c=0;

    float maiorVlr = maiorValor(dados);
    float menorVlr = menorValor(dados);
    float amplitude = (maiorVlr-menorVlr)/ nFaixas;

    fxs = (float **) malloc(sizeof(float *)* nFaixas);

    for (linhas =0; linhas< nFaixas; linhas++)
    {
        fxs[linhas] = (float *) malloc(4*sizeof(float));

        float freqAbs=0;
        float freqRel=0;

        for(l=0; l<10; l++)
        {
            float limInf = menorVlr+amplitude*linhas;
            float limSup = menorVlr+amplitude*(linhas+1);

            for(c=0; c<3; c++)
            {
                if (m[l][c]== menorVlr && m[l][c]>=limInf && m[l][c]<=limSup)
                    freqAbs++;
                else if (m[l][c]>limInf && m[l][c]<=limSup)
                    freqAbs++;
            }

            freqRel= freqAbs/10*3;

            fxs[linhas][0]=limInf;
            fxs[linhas][1]=limSup;
            fxs[linhas][2]=freqAbs;
            fxs[linhas][3]=freqRel;
        }
    }

    imprFaixas(fxs, nFaixas, 4);

    return fxs;
}

int main()
{
    setlocale(LC_ALL, "");
    float **faixas;
    printf("Dados iniciais:\n\n");
    imprDados(dados);
    printf("\n");
    printf("Menor valor: %.2f\n", menorValor(dados));
    printf("Maior valor: %.2f\n", maiorValor(dados));
    printf("Média dos valores: %.2f\n", mediaValores(dados));
    printf("\n");
    faixas = geraFaixas(dados, 5);
    return 0;
}
