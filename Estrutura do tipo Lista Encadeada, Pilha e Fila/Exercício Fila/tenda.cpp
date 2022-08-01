#include <stdio.h>
#include <stdlib.h>
#include "tenda.h"

Fila* cria (void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

/* função auxiliar: insere no fim */
No* ins_fim (No* fim)
{
    No* p = (No*) malloc(sizeof(No));
    if (fim != NULL) /* verifica se lista não estava vazia */
    {
        p->senha = fim->senha+1;
        p->prox = NULL;
        fim->prox = p;
    }
    else
    {
        p->senha = 1;
        p->prox = NULL;
    }

    return p;
}

void insere (Fila* f)
{
    f->fim = ins_fim(f->fim);
    if (f->ini==NULL) /* fila antes vazia? */
        f->ini = f->fim;
}

/* função auxiliar: retira do início */
No* ret_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

float retira (Fila* f)
{
    int v;
    if (vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    v = f->ini->senha;
    f->ini = ret_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
        f->fim = NULL;
    return v;
}

int vazia (Fila* f)
{
    return (f->ini==NULL);
}

void libera (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

/* imprime: versão com lista */
void imprime (Fila* f)
{
    No* q;
    for (q=f->ini; q!=NULL; q=q->prox)
        printf("%5d\n",q->senha);
}

int conta(Fila *f)
{
    No *teste = f->ini;
    int cont = 0;

    if ( f->ini != NULL && f->fim != NULL)
    {
        while( f->fim != teste)
        {
            teste = teste->prox;
            cont++;
        }
        cont++;
    }

    return cont;
}
