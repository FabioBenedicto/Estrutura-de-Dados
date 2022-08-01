#include <stdio.h>

void impVetint(int *v, int nElementos)
{
    int x;
    for(x=0; x<nElementos; x++)
    {
        printf("%d ", v[x]);
    }
    printf("\n");
}

int escalar(int *vetor1, int *vetor2, int nElementos)
{
    int x;
    int escalar=0;
    for(x=0; x<nElementos; x++)
    {
        escalar+=(vetor1[x]*vetor2[x]);
    }
    return escalar;
}

int todosDiferentes(int *vetor, int nElementos)
{
    int x;
    int y;
    int diferentes = 1;

    for(x=0; x<nElementos; x++)
    {
        for(y=x+1; y<nElementos; y++)
        {
            if (vetor[x]==vetor[y])
            {
                diferentes=0;
                break;
            }
        }
        if (diferentes==0)
        {
            break;
        }
    }
    return diferentes;
}

void rotaciona (int *vetor, int nElementos)
{
    int x;
    int y=vetor[nElementos-1];

    for(x=nElementos-1; 0<=x; x--)
    {
        if (x==0)
        {
            vetor[x]=y;
        }
        else
        {
            vetor[x]=vetor[x-1];
        }
    }
    return;
}

int contaValores(int *vetor, int nElemento, int limInf, int limSup)
{
    int x;
    int valores=0;

    for (x=0; x<nElemento; x++)
    {
        if ((vetor[x]<=limSup) && (vetor[x]>=limInf))
        {
            valores++;
        }
    }
    return valores;
}

int menorElemento(int *vetor, int nElementos)
{
    int x;
    int menor=0;

    for(x=0; x<nElementos; x++)
    {
        if(vetor[x] < vetor[menor])
        {
            menor=x;
        }
    }
    return menor;
}

int maiorElemento(int *vetor, int nElementos)
{
    int x;
    int maior=0;

    for(x=0; x<nElementos; x++)
    {
        if(vetor[x] > vetor[maior])
        {
            maior=x;
        }
    }
    return maior;
}

int contidos(int *v1, int nElementos1, int *v2, int nElementos2)
{
    int x;
    int y;
    int contidos = 0;

    for(x=0; x<nElementos2; x++)
    {
        for(y=0; y<nElementos1; y++)
        {
            if (v2[x] == v1[y])
            {
                contidos++;
                break;
            }
        }
    }

    return contidos;
}
