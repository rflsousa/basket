#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float altura[10], media, maiorAltura = 0, menorAltura = 3, mediana, desvioPadrao, totalAlturas;
char nome[10][30];//numero de linhas e caracteres
int c; //contador

void dadosJogadores()
{
    //leitura
    printf("\n\n  \tNOMES E ALTURAS\n\n");
    for(c = 0 ; c < 10; c++)
    {
        printf("%s\t", nome[c]);
        printf("\t\t%.2f\n", altura[c]);
    }
}

float mediaAlturas()
{

    for(c = 0; c < 10; c++)
    {
        media+= altura[c];
    }

    media = media / 10.0;

    printf("\nMedia das alturas: %.2f\n", media);

    return media;
}

float desvioPadraoAltura()
{
    if(media > 0){
        for(c = 0; c < 10 ; c++)
        {
            totalAlturas += altura[c];
        }

        for(c = 0; c < 10 ; c++)
        {
            desvioPadrao += (sqrt(altura[c]) / totalAlturas);
        }

        desvioPadrao = desvioPadrao - sqrt(media);
        printf("Desvio padrao: %.2f\n", fabs(desvioPadrao));

    }
    else
    {
        printf("Para saber o desvio padrao, calcule primeiro a media das alturas na opcao 2.\n");
        return 0.0;
    }

}

float maiorMenorAltura()
{
    int indexNomeMaior, indexNomeMenor;

    for(c = 0; c < 10; c++)
    {
        if(altura[c] > maiorAltura)
        {
            maiorAltura = altura[c];
            indexNomeMaior = c;
        }

        else if(altura[c] < menorAltura)
        {
            menorAltura = altura[c];
            indexNomeMenor = c;
        }
    }

    printf("\nMaior altura:\n");
    printf("%s, altura: %.2f", nome[indexNomeMaior], maiorAltura);

    printf("\nMenor altura:\n");
    printf("%s, altura: %.2f", nome[indexNomeMenor], menorAltura);

    return maiorAltura, menorAltura;

}

int comparador(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

float medianaAlturas()
{
    float alturaCopia[10];
    for(c = 0; c < 10; c++)
    {
        alturaCopia[c] = altura[c];
    }

    qsort(alturaCopia, 10, sizeof(float), comparador);

    mediana = (alturaCopia[4] + alturaCopia[5])/ 2.0;
    printf("Mediana: %.2f\n", mediana);

    return mediana;
}

int main()
{

    int verificador = 1;

    printf(" APS DE TECNICAS DE PROGRAMACAO\n\n");
    printf(" NOME DO ALUNO: Jhonas Fernandes Souto\tRA: 21106806");

    //inserção de dados
    printf("\n\n\n\n ===TIME DE BASQUETE===\n");

    for(c = 0; c < 10; c++)
    {
        printf("\n Nome do %i jogador:\t", (c+1));
        scanf("%s", &nome[c]);

        printf(" Altura dele:\t\t");
        scanf("%f", &altura[c]);

        while(altura[c] < 0 || altura[c] >= 3)
        {
            printf("Valor invalido. A altura deve estar entre 0 e 3 metros ! \n");
            printf("Digite novamente a altura!\n\n");

            printf(" Altura do %i jogador:\t\t", (c+1));
            scanf("%f", &altura[c]);

        }
    }

    do
    {
        int menu;

        printf("\n\n\n\n ===TIME DE BASQUETE===\n");
        printf("1 - Dados dos jogadores\n");
        printf("2 - Media de alturas\n");
        printf("3 - Desvio padrao das alturas\n");
        printf("4 - Maior e Menor altura\n");
        printf("5 - Mediana das alturas\n");
        printf("0 - Finalizar\n\n");

        printf("Digite um numero de alguma opcao acima ou 0 para finalizar\n");
        scanf("%i", &menu);

        switch(menu){
            case 1:
                dadosJogadores();
                break;
            case 2:
                mediaAlturas();
                break;
            case 3:
                desvioPadraoAltura();
                break;
            case 4:
                maiorMenorAltura();
                break;
            case 5:
                medianaAlturas();
                break;
            case 0:
                verificador = 0;
                printf("FIM DO PROGRAMA.\n");
                break;

            default:
               printf("Opcao invalida, tente novamente!\n");

        }
    }while(verificador == 1);

    return 0;

}
