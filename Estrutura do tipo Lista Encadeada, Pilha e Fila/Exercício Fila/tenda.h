#ifndef TENDA_H_INCLUDED
#define TENDA_H_INCLUDED

struct no
{
    int senha;
    struct no* prox;
};

typedef struct no No;

struct fila
{
    No* ini;
    No* fim;
};

typedef struct fila Fila;
Fila* cria (void);
void insere (Fila* f);
float retira (Fila* f);
int vazia (Fila* f);
void libera (Fila* f);
void imprime (Fila* f);
int conta(Fila *f);

#endif // TENDA_H_INCLUDED
