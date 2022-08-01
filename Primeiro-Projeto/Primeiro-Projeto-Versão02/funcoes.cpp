#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>

void traco(int n, char ch) {
    for (int x=0; x<n; x++)
        putch(ch);
}

int menu(){

    int op = 0;

    do {
        system("cls");
        traco(20,'=');
        putch('\n');
        printf("1 - Imprimir Boletim\n");
        printf("2 - Lançamentos\n");
        traco(20,'-');
        putch('\n');
        printf("9 - Configurações\n");
        traco(20,'-');
        putch('\n');
        printf("0 - Sair\n");
        traco(20,'=');
        putch('\n');

        scanf("%d", &op);
        fflush(stdin);
        if ((op >= 0 && op <= 2) || op==9){
            return op;
        } else {
            system("cls");
            printf("Opção inválida, Digite qualquer tecla!\n\n");
            while (!(_kbhit())){}
        }

    } while(1);

    return 0;
}

char * getPathExec(){
    char * caminho;
    caminho = (char *) malloc(256);

    getcwd(caminho, 255);

    strcat(caminho, "\\");
    return caminho;
}

void saveConfig() {
    FILE * fcfg;
    char nameFile[256];

    extern char pAno[5];
    extern char pTurma[11];
    extern char pSerie[2];
    extern char pDisc[11];

    system("cls");
    printf("Configurações\n");
    traco(40,'=');
    printf("\nAno letivo: ");
    scanf("%s", pAno);
    printf("Turma: ");
    scanf("%s", pTurma);
    printf("Série: ");
    scanf("%s", pSerie);
    printf("Disciplina: ");
    scanf("%s", pDisc);
    strcpy(nameFile, getPathExec());
    strcat(nameFile,"config.cfg");

    fcfg = fopen(nameFile, "w");
    if(fcfg == NULL) {
        printf("Falha ao salvar configurações!\n\n");
        printf("Pressione qualquer tecla...");
        getche();
        return;
    }

    fprintf(fcfg, "%s %s %s %s\n",pAno,pTurma,pSerie,pDisc);
    fclose(fcfg);
    return;
}

void loadConfig() {
    FILE * fcfg;
    char nameFile[256];

    extern char pAno[5];
    extern char pTurma[11];
    extern char pSerie[2];
    extern char pDisc[11];

    strcpy(nameFile, getPathExec());
    strcat(nameFile, "config.cfg");

    fcfg = fopen(nameFile, "r");
    if(fcfg == NULL) {
        printf("Falha ao abrir arquivo de configuração [%s]\n\n", nameFile);
        printf("Pressione [ENTER] para continuar...");
        getche();
        return;
    }

    fscanf(fcfg,"%s %s %s %s", pAno, pTurma, pSerie, pDisc);

    fclose(fcfg);

    return;

}

char * getFileName() {
    extern char pData[256];
    extern char pAno[5];
    extern char pTurma[11];
    extern char pSerie[2];
    extern char pDisc[11];

    char * fName;

    fName = (char *) malloc(sizeof(char) * 256);

    strcpy(fName,pData);
    strcat(fName,pAno);
    strcat(fName,"-");
    strcat(fName,pTurma);
    strcat(fName,"-");
    strcat(fName,pSerie);
    strcat(fName,"-");
    strcat(fName,pDisc);
    strcat(fName,".dat");

    return fName;
}

void imprimirBoletim() {

    FILE * fd;
    char nameFile[256];

    char linha[101];
    char ra[11];
    float ns1, ns2, somaNS1, somaNS2, somaFS1, somaFS2, mediaAluno;
    int fs1, fs2, numAlunos;
    char situacao[11];

    strcpy(nameFile, getFileName());

    fd = fopen(nameFile, "r");
    if (fd == NULL) {
        printf("Falha ao abrir o arquivo de dados!\n\n");
        printf("Pressione qualquer tecla...");
        getche();
        return;
    }

    printf("\n");
    printf("%-10s %10s %10s %10s %10s %12s\n","RA","NS1","NS2","FS1","FS2", "Situação  ");
    printf("%-10s %10s %10s %10s %10s %12s\n","--","---","---","---","---", "------------");

    strcpy(ra, "");
    ns1=0.0;
    ns2=0.0;
    fs1=0;
    fs2=0;

    while(fgets(linha,100,fd)!= NULL){
        sscanf(linha,"%s %f %f %d %d",ra, &ns1, &ns2, &fs1, &fs2);
        somaNS1 += ns1;
        somaNS2 += ns2;
        somaFS1 += fs1;
        somaFS2 += fs2;
        numAlunos ++;

        mediaAluno = (ns1 + ns2)/2;

        if(mediaAluno >= 6)
            strcpy(situacao, "Aprovado");
        else if (mediaAluno >= 3)
            strcpy(situacao, "Dependencia");
        else
            strcpy(situacao, "Reprovado");


        printf("%-10s %10.1f %10.1f %10d %10d %12s\n",ra, ns1, ns2, fs1, fs2, situacao);
    }

    printf("%-10s %10s %10s %10s %10s\n","------","---","---","---","---");
    printf("%-10s %10.1f %10.1f %10.1f %10.1f\n","Médias",somaNS1/numAlunos, somaNS2/numAlunos, somaFS1/numAlunos, somaFS2/numAlunos);

    printf("\nPressione [ENTER] para retornar ao menu...");
    getche();
    return;
}

void lancamentos() {
    FILE * fd;
    char nameFile[256];
    char ra[11];
    float ns1, ns2;
    int fs1, fs2;

    strcpy(nameFile, getFileName());

    fd = fopen(nameFile, "a");

    if (fd == NULL) {
        printf("Falha ao abrir o arquivo de dados!\n\n");
        printf("Pressione qualquer tecla...");
        getche();
        return;
    }

    do {
        system("cls");
        strcpy(ra, "");
        ns1=0.0;
        ns2=0.0;
        fs1=0;
        fs2=0;

        fflush(stdin);
        printf("RA (Vazio para sair): ");
        gets(ra);

        if(strlen(ra) == 0) break;

        printf("Nota Semestre 1: ");
        scanf("%f", &ns1);
        printf("Faltas Semestre 1: ");
        scanf("%d", &fs1);

        printf("Nota Semestre 2: ");
        scanf("%f", &ns2);
        printf("Faltas Semestre 2: ");
        scanf("%d", &fs2);

        fprintf(fd, "\n%s %5.2f %5.2f %d %d", ra, ns1, ns2, fs1, fs2);

    } while(1);

    fclose(fd);
    return;
}


