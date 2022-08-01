#ifndef VETORES_H_INCLUDED
#define VETORES_H_INCLUDED

void impVetint(int *v, int nElementos);
int escalar (int *vetor1, int *vetor2, int nElementos);
int todosDiferentes(int *vetor, int nElementos);
void rotaciona (int *vetor, int nElementos);
int contaValores(int *vetor, int nElemento, int limInf, int limSup);
int menorElemento(int *vetor, int nElementos);
int maiorElemento(int *vetor, int nElementos);
int contidos(int *v1, int nElementos1, int *v2, int nElementos2);

#endif // VETORES_H_INCLUDED
