#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

const int MIN = 0;
const int MAX = 10;
const int kbCIMA = 72;
const int kbBAIXO = 80;
const int kbDIREITA = 77;
const int kbESQUERDA = 75;
const int kbESC = 27;

typedef struct no {
    int info;
    struct no* prox;
};
typedef struct no No;

struct pilha {
    No* prim;
};
typedef struct pilha Pilha;

int lerTecla();
int lerTopo(Pilha* p);
Pilha* cria();
void push (Pilha* p, int v);
int pop (Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);
void imprime(Pilha* p);

#endif // PILHA_H_INCLUDED
