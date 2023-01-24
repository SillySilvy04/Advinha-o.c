#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    printf("===============================\n");
    printf("bem vindo ao jogo de advinhação\n");
    printf("===============================\n");

    int segundos = time(0);
    srand(segundos);

    int numero = (rand()%100);
    int chute;
    int tentativas = 0;
    float pontos = 1000;

    int acertou=0;
    int numerotentativas;

    int nivel;
    printf("qual o nivel de dificuldade desejado?:\n");
    printf("(1)facil (2)medio (3)dificil\n\n");
    printf("escolha: ");
    scanf("%d", &nivel);

    switch(nivel)
    {
        case 1: numerotentativas =20; break;
        case 2: numerotentativas =13; break;
        default : numerotentativas =6; break;
    }


    for(int i=1;i<=numerotentativas;i++)
    {    
        printf("tentativa numero %d de %d\n", tentativas += 1, numerotentativas);
        printf("insira sua tentativa: ");
        scanf("%d", &chute);

        if (chute<0)
        {
            printf("numero negativo nã ovale, bobo\n");
            continue;
        }
        acertou = (chute==numero);
        int maior = (chute>numero);
        int menor = (chute<numero);


        if (acertou)
        {
            break;
        }        
        else if (maior)
        {
            printf("seu chute foi maior do que o numero do programa\n");
        }
        else if (menor)
        {
            printf("seu chute foi menor do que o numero do programa\n");
        } 

        float pontosperdidos = (double)(chute-numero)/2;
        pontos = pontos - abs(pontosperdidos);     
    }
    
    if (acertou)
    {
        printf("voce ganhou!\n");
        printf("pontuacao: %.1f", pontos);
    }
    else
    {
        printf("voce perdeu!\n fim de jogo");
    }
}