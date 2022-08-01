/*
Pedro Losso Quintans - 200146
Fábio Henrique Benedicto - 200126
3INFD
Data: 27/05/2021
*/

#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

struct cidade
{
    char nome[30];
    int coordX;
    int coordY;
};

int main()
{
    int dy, dx, a, b, numCidades = 6;
    float dist, distTotal;
    cidade cidades[numCidades - 1];

    strcpy(cidades[0].nome, "Cidade Um");
    cidades[0].coordX = 2;
    cidades[0].coordY = 2;

    strcpy(cidades[1].nome, "Cidade Dois");
    cidades[1].coordX = 10;
    cidades[1].coordY = 4;

    strcpy(cidades[2].nome, "Cidade Tres");
    cidades[2].coordX = 19;
    cidades[2].coordY = 8;

    strcpy(cidades[3].nome, "Cidade Quatro");
    cidades[3].coordX = 16;
    cidades[3].coordY = 15;

    strcpy(cidades[4].nome, "Cidade Cinco");
    cidades[4].coordX = 5;
    cidades[4].coordY = 19;

    strcpy(cidades[5].nome, "Cidade Seis");
    cidades[5].coordX = 8;
    cidades[5].coordY = 10;

    for(a=0; a<numCidades; a++)
    {
        if (a != numCidades-1)
        {
            b=a+1;
        }
        else
        {
            b=0;
        }

        dx = abs(cidades[a].coordX - cidades[b].coordX);
        dy = abs(cidades[a].coordY - cidades[b].coordY);
        dist = sqrt(pow(dx,2) + pow(dy,2));
        distTotal += dist;
        printf("De %s a %s = %5.2f\n", cidades[a].nome, cidades[b].nome, dist);
    }

    printf("\nDitancia total percorrida = %5.2f\n", distTotal);
}
