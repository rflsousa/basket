#include <stdio.h>
#include <stdlib.h>

int main()
{

    float altura[10], altura_media;
    char nome[10][30];//numero de linhas e caracteres
    int c; //contador

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

    //leitura
    printf("\n\n  \tNOMES E ALTURAS\n\n");
    for(c = 0 ; c < 10; c++)
    {
        printf(" %s\t", nome[c]);
        printf(" \t\t%.2f\n", altura[c]);
    };
    return 0;

}
