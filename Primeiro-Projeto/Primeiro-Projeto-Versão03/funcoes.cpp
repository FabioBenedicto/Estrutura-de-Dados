#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include "funcoes.h"

void traco(int n, char ch)
{
    for(int x=0; x<n; x++)
        putch(ch);
}

int menu()
{
    int op=0;

    do
    {
        system ("cls");
        traco(20, '=');
        putch('\n');
        printf ("1 = imprimir boletim\n");
        printf ("2 = lançamentos\n");
        traco(20, '-');
        putch('\n');
        printf ("9 = Configurações\n");
        traco(20, '-');
        putch('\n');
        printf ("0 = Sair\n");
        traco(20, '=');
        putch('\n');
        /*op=getchar();*/

        scanf ("%d", &op);
        if ((op >=0 && op <=2) || op==9)
            return op;
        else
        {
            system("cls");
            printf("Opção inválida, Digite qualquer tecla!\n");
            while (!(_kbhit()));
        }
    }
    while (1);
}
char * getPathExec()
{
    char * caminho;
    caminho=(char*) malloc(256);

    getcwd(caminho, 255); // retorna o 'path' do programa

    strcat(caminho, "\\");
    return caminho;
}

char * getFileName()
{
    extern char pData[256];
    extern char pAno[5];
    extern char pTurma[11];
    extern char pSerie[2];
    extern char pDisc[11];

    char * fName;

    fName= (char*) malloc(sizeof(char)*256);

    strcpy(fName, pData);
    strcat(fName, pAno);
    strcat(fName, "-");
    strcat(fName, pTurma);
    strcat(fName, "-");
    strcat(fName, pSerie);
    strcat(fName, "-");
    strcat(fName, pDisc);
    strcat(fName, ".dat");

    return fName;
}

void loadVectors()
{

    FILE * fd;
    char nameFile[256];

    extern char vRa[40][7];
    extern float vNS1[40];
    extern float vNS2[40];
    extern float vFS1[40];
    extern float vFS2[40];
    extern int nEl;

    char linha [101];
    char ra[11];
    float ns1, ns2, fs1, fs2;

    strcpy(nameFile, getFileName());

    printf("\n\n%s\n\n", nameFile);
    getche();
    fflush(stdin);

    fd=fopen(nameFile,"r");

    if (fd==NULL)
    {
        printf("falha ao abrir o arquivo de dados!");
        printf ("Presione qq. tecla...");
        getche();
        return;
    }

    strcpy (ra, "");
    ns1= 0.00;
    ns2= 0.00;
    fs1= 0.00;
    fs2= 0.00;
    nEl=0;

    while (fgets(linha,100,fd)!= NULL)
    {
        sscanf(linha, "%s %f %f %f %f", &ra, &ns1, &ns2, &fs1, &fs2);

        strcpy(vRa[nEl], ra);
        vNS1[nEl]=ns1;
        vNS2[nEl]=ns2;
        vFS1[nEl]=fs1;
        vFS2[nEl]=fs2;
        nEl++;
    }

    fclose(fd);
    return;
}

void writeVectors()
{

    FILE * fd;
    char nameFile[256];

    extern char vRa[40][7];
    extern float vNS1[40];
    extern float vNS2[40];
    extern float vFS1[40];
    extern float vFS2[40];
    extern int nEl;

    int _nEl=0;

    strcpy(nameFile, getFileName());

    fd=fopen(nameFile, "w");

    if (fd==NULL)
    {
        printf("Falha ao salvar configurações!\n\n");
        printf("Pressione [ENTER] para retornar ao menu...\n");
        getche();
        return;
    }

    for (_nEl=0; _nEl<nEl; _nEl++)
    {

        fprintf(fd, "%s %.1f %.1f %f %f\n",
                vRa[_nEl],
                vNS1[_nEl],
                vNS2[_nEl],
                vFS1[_nEl],
                vFS2[_nEl]);

    }

    fclose(fd);
    printf("Pressione [ENTER] para retornar...\n");
    getche();
    return;
}

void imprimirBoletimVector()
{
    extern char vRa[40][7];
    extern float vNS1[40];
    extern float vNS2[40];
    extern float vFS1[40];
    extern float vFS2[40];
    extern int nEl;

    float mediaAluno;
    char situacao[13];
    int aprovados;
    float somns1=0.0, somns2=0.0, somfs1=0.0, somfs2=0.0, sommedia;

    int _nEl;

    loadVectors();

    printf ("\n");
    printf ("%-10s %10s %10s %10s %10s %10s %15s\n", "RA", "NS1", "NS2", "FS1", "FS2", "Média", "Situação");
    printf ("%-10s %10s %10s %10s %10s %10s %15s\n", "-----", "----", "----", "----", "----", "------", "---------");


    for(_nEl = 0; _nEl<nEl; _nEl++)
    {

        mediaAluno=(vNS1[_nEl]+vNS2[_nEl])/2;

        if(mediaAluno>=6)
        {
            strcpy(situacao,"Aprovado");
            aprovados++;
        }
        else if(mediaAluno>=3.5)
            strcpy(situacao,"Dependência");
        else
            strcpy(situacao,"Reprovado");

        printf("%-10s %10.1f %10.1f %10.0f %10.0f %10.1f %15s\n", vRa[_nEl], vNS1[_nEl], vNS2[_nEl], vFS1[_nEl], vFS2[_nEl], mediaAluno, situacao);

        somns1+= vNS1[_nEl];
        somns2+= vNS2[_nEl];
        somfs1+= vFS1[_nEl];
        somfs2+= vFS2[_nEl];
        sommedia+=mediaAluno;

    }

    printf ("%-10s %10s %10s %10s %10s %10s %15s\n", "-----", "----", "----", "----", "----", "------", "---------");
    printf("%-10s %10.1f %10.1f %10.1f %10.1f %10.1f %10d Ap.\n", "Médias", somns1/nEl, somns2/nEl, somfs1/nEl, somfs2/nEl, sommedia/nEl, aprovados);
    printf("\nPressione [ENTER] para retornar...\n");
    getche();
    return;
}

void lancamentosVector()
{

    extern char vRa[40][7];
    extern float vNS1[40];
    extern float vNS2[40];
    extern float vFS1[40];
    extern float vFS2[40];
    extern int nEl;

    char ra[11];
    float ns1, ns2, fs1, fs2;

    loadVectors();

    do
    {
        system("cls");
        printf("Lançamentos\n");
        traco(40, '=');
        printf("\n");

        if (nEl>39)
        {
            printf("Atingiu o limite máximo de dados!\n");
            printf("\n\nPressiones [Entrer] para voltar...\n");
            getche();
            return;
        }

        strcpy (ra, ""); //limpa a variável
        ns1= 0.0;
        ns2= 0.0;
        fs1= 0.0;
        fs2= 0.0;

        fflush(stdin);
        printf("\nRA (vazio para sair): ");
        gets(ra);
        printf("\n");
        if (strlen(ra)==0)
            break;
        printf("Nota semestre 1: ");
        scanf("%f", &ns1);
        printf("\n");
        printf("Nota semestre 2: ");
        scanf("%f", &ns2);
        printf("\n");
        printf("Faltas semestre 1: ");
        scanf("%f", &fs1);
        printf("\n");
        printf("Faltas semestre 2: ");
        scanf("%f", &fs2);
        printf("\n");

        strcpy(vRa[nEl], ra);
        vNS1[nEl]=ns1;
        vNS2[nEl]=ns2;
        vFS1[nEl]=fs1;
        vFS2[nEl]=fs2;
        nEl++;

    }
    while(1);

    writeVectors();

    return;
}

void saveConfig ()
{
    FILE * fcfg;
    char nameFile[256];

    extern char pAno[5];
    extern char pTurma[11];
    extern char pSerie[2];
    extern char pDisc[11];

    system("cls");
    printf("Configurações\n");
    traco(40, '=');
    printf("\n");
    printf ("\nAno letivo:");
    scanf ("%s", pAno);
    printf("\n");
    printf ("Turma: ");
    scanf("%s", pTurma);
    printf("\n");
    printf("Série: ");
    scanf("%s", pSerie);
    printf("\n");
    printf("Disciplina: ");
    scanf("%s", pDisc);
    printf("\n");
    strcpy(nameFile, getPathExec());
    strcat(nameFile,"config.cfg");

    fcfg=fopen(nameFile, "w");
    if (fcfg==NULL)
    {
        printf("Falha ao salvar configurações!\n\n");
        printf("Pressione [ENTER] para retornar ao menu...");
        getche();
        return;
    }

    fprintf(fcfg, "%s %s %s %s\n", pAno, pTurma, pSerie, pDisc);
    fclose(fcfg);
    return;
}

void loadConfig()
{

    setlocale (LC_ALL, "Portuguese");
    FILE * fcfg;
    char namefile[256];

    extern char pAno[5];
    extern char pTurma[11];
    extern char pSerie[2];
    extern char pDisc[11];

    strcpy(namefile, getPathExec());
    strcat(namefile, "config.cfg");

    fcfg=fopen(namefile, "r");
    if (fcfg==NULL)
    {

        printf("falha ao abrir o arquivo de configuração [%s]\n\n", namefile);
        printf ("Presione [ENTER] tecla...");
        getche();
        return;
    }

    fscanf(fcfg,"%s %s %s %s", pAno, pTurma, pSerie, pDisc);
    fclose(fcfg);
    return;
}

