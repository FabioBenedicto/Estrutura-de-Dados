#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include "pilha.h"

int lerTecla()
{
    int tecla = getch();
    if(!tecla)
    {
        tecla = getch();
    }
    setbuf(stdin,NULL);
    return tecla;
}

int lerTopo(Pilha* p)
{
    int valor = -1;
    if(!vazia(p))
    {
        No* n = p->prim;
        while(n != NULL)
        {
            valor = n->info;
            n = n->prox;
        }
    }
    return valor;
}


Pilha* cria()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
};

void push (Pilha* p, int v)
{
    No* n = (No*) malloc (sizeof(No));
    n->prox = p->prim;
    n->info = v;
    p->prim = n;
    return;
};

int vazia(Pilha* p)
{
    return (p->prim == NULL);
}

int pop (Pilha* p)
{
    int v = 0;
    No* n = p->prim;
    if (vazia(p) != 1)
    {

        p->prim = n->prox;
        v = n->info;
        free(n);
    }
    return v;
};

void libera (Pilha* p)
{
    int numero = 0;
    No* n = p->prim;
    while (n != NULL)
    {
        No* n = n->prox;
        free(n);
        p->prim = n;
    }
    return;
}

void imprime(Pilha* p)
{
    if(!vazia(p))
    {
        No* n = p->prim;
        while(n != NULL)
        {
            printf("%d \n", n->info);
            n = n->prox;
        }
    }
    return;
}
