//Fábio Henrique Benedicto 2ºMINFD 200126 06/11/2021
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct lista
{
    int info;
    struct lista *proximo;
};

typedef struct lista Lista;

Lista* inicializa()
{
    return NULL;
}

int vazia(Lista* lst)
{
    return (lst == NULL);
}

Lista *insere(Lista *lst, int _info)
{
    Lista * novo;
    novo = (Lista *) malloc(sizeof(Lista));
    novo->info = _info;
    novo->proximo = lst;
    return novo;
}

Lista * busca(Lista * l, int num)
{
    Lista * p;

    if(vazia(l))
    {
        return NULL;
    }

    for (p=l; p!=NULL; p=p->proximo)
    {
        if (p->info == num)
            return p;
    }

    return NULL; /* não achou o elemento */
}

void imprimeLst(Lista *lst)
{
    Lista *temp;
    if (vazia(lst))
    {
        printf("Lista Vazia!");

        return;
    }

    for(temp = lst; temp!=NULL; temp = temp->proximo)
    {
        printf("%d ", temp->info);
    }
}

void libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->proximo; //Guarda a referência para o proximo item
        free(p); // Libera a memória da variavel p
        p = t; // Faz p apontar para o proximo
    }
}

Lista *separa(Lista *l, int n)
{
    Lista *l1;
    Lista *l2;
    l1 = l;
    while(l1->info!= n && l1->proximo!= NULL)
    {
        l1=l1->proximo;
    }
    l2=l1->proximo;
    l1->proximo=NULL;
    return l2;
}

Lista *concatena (Lista * l1, Lista* l2)
{
    Lista *lst1 = l1;
    if(vazia(l1))
    {
        return l2;
    }

    if(vazia(l2))
    {
        return l1;
    }

    while(lst1->proximo!= NULL)
    {
        lst1=lst1->proximo;
    }
    lst1->proximo=l2;
    return l1;
}

Lista *constroi (int n, int* v)
{
    Lista *lst;
    lst= inicializa();
    if (n!=0)
    {
        for(int nEl=n-1; nEl>=0; nEl--)
        {
            lst = insere(lst, v[nEl]);
        }
    }
    return lst;
}

Lista *retira_prefixo (Lista * l, int n)
{
    Lista *lst;
    for(int nEl=0; nEl<n; nEl++)
    {
        lst= l;
        if (lst == NULL)
            break;
        l= l->proximo;
        free(lst);
    }
    return l;
}

int main()
{
    Lista *lista1;
    Lista *lista2;
    lista1 = inicializa();
    lista2 = inicializa();

    lista1 = insere(lista1, 5);
    lista1 = insere(lista1, 4);
    lista1 = insere(lista1, 3);
    lista1 = insere(lista1, 2);
    lista1 = insere(lista1, 1);
    lista2 = insere(lista2, 10);
    lista2 = insere(lista2, 9);
    lista2 = insere(lista2, 8);
    lista2 = insere(lista2, 7);
    lista2 = insere(lista2, 6);

    printf("Primeira lista: ");
    imprimeLst(lista1);
    printf("\n");
    printf("Segunda lista: ");
    imprimeLst(lista2);

    printf("\n\n");

    printf("Separa: ");
    Lista *lista3;
    lista3 = inicializa();
    lista3 = separa(lista1, 3);
    imprimeLst(lista3);

    printf("\n");

    printf("Concatena: ");
    Lista *lista4;
    lista4 = inicializa();
    lista4 = concatena(lista3, lista2);
    imprimeLst(lista4);

    printf("\n");

    printf("Constroi: ");
    Lista *lista5;
    lista5 = inicializa();
    int vetor[]= {1, 2, 3, 4, 5};
    lista5 = constroi(5, vetor);
    imprimeLst(lista5);

    printf("\n");

    printf("Retira prefixo: ");
    Lista *lista6;
    lista6 = inicializa();
    lista6 = retira_prefixo(lista3, 2);
    imprimeLst(lista6);

    printf("\n\n");

    printf("FIM");

    libera(lista1);
    libera(lista2);
    libera(lista3);
    libera(lista4);
    libera(lista5);

     printf("\n");

    return 0;
}
