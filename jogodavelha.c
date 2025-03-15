#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define QTD_colunas 3
#define QTD_linhas 3

#define EMPATE 'E'
#define CARACTER '_'

#define JOGADOR_x 'X'
#define JOGADOR_o 'O'

int main()
{
    /*  --MODELO--
        [0] [1] [2]
      [0] _  _  _
      [1] _  _  _  X
      [2] _  _  _  O
    */

    int linha;
    int coluna;

    int posicao;

    int jogadas = 0;

    char jogador = JOGADOR_x;
    int ganhador = EMPATE;

    // TABULEIRO
    char tabuleiro[QTD_linhas][QTD_colunas];

    for (linha = 0; linha < QTD_linhas; linha += 1)
        for (coluna = 0; coluna < QTD_colunas; coluna += 1)
            tabuleiro[linha][coluna] = CARACTER;

    while (1)
    {
        for (linha = 0; linha < QTD_linhas; linha += 1)
        {
            for (coluna = 0; coluna < QTD_colunas; coluna += 1)
                printf("%c ", tabuleiro[linha][coluna]);

            printf("\n");
        }

        printf("Jogador %c sua vez", jogador);
        scanf("%d", &posicao);

        if (!(posicao >= 1 && posicao <= 9))
        {
            printf("Posicao invalida\n");

            continue;
        }

        int posicao_linha = (posicao - 1) / QTD_linhas;
        int posicao_coluna = (posicao - 1) % QTD_colunas;
        
        if (tabuleiro[posicao_linha][posicao_coluna] != CARACTER)
        {
            printf("Esse espaço ja foi preenchido\n");

            continue;
        }

        tabuleiro[posicao_linha][posicao_coluna] = jogador;

        for (linha = 0; linha < QTD_linhas; linha += 1)
        {
            if (tabuleiro[linha][0] == JOGADOR_x && tabuleiro[linha][1] == JOGADOR_x && tabuleiro[linha][2] == JOGADOR_x)
            {
                printf("Parabens voce ganhou\n");
                ganhador = JOGADOR_x;

                break;
            }
        }

        for (coluna = 0; coluna < QTD_colunas; coluna += 1)
        {
            if (tabuleiro[0][coluna] == JOGADOR_x && tabuleiro[1][coluna] == JOGADOR_x && tabuleiro[2][coluna] == JOGADOR_x)
            {
                printf("Parabens voce ganhou\n");
                ganhador = JOGADOR_x;

                break;
            }
        }

        if (tabuleiro[0][0] == JOGADOR_x && tabuleiro[1][1] == JOGADOR_x && tabuleiro[2][2] == JOGADOR_x)
            ganhador = JOGADOR_x;

        else if (tabuleiro[0][2] == JOGADOR_x && tabuleiro[1][1] == JOGADOR_x && tabuleiro[2][0] == JOGADOR_x)
            ganhador = JOGADOR_x;
        

            for (linha = 0; linha < QTD_linhas; linha += 1)
        {
            if (tabuleiro[linha][0] == JOGADOR_o && tabuleiro[linha][1] == JOGADOR_o && tabuleiro[linha][2] == JOGADOR_o)
            {
                printf("Parabens voce ganhou\n");
                ganhador = JOGADOR_o;

                break;
            }
        }

        for (coluna = 0; coluna < QTD_colunas; coluna += 1)
        {
            if (tabuleiro[0][coluna] == JOGADOR_o && tabuleiro[1][coluna] == JOGADOR_o && tabuleiro[2][coluna] == JOGADOR_o)
            {
                printf("Parabens voce ganhou\n");
                ganhador = JOGADOR_o;

                break;
            }
        }

        if (tabuleiro[0][0] == JOGADOR_o && tabuleiro[1][1] == JOGADOR_o && tabuleiro[2][2] == JOGADOR_o)
            ganhador = JOGADOR_o;

        else if (tabuleiro[0][2] == JOGADOR_o && tabuleiro[1][1] == JOGADOR_o && tabuleiro[2][0] == JOGADOR_o)
            ganhador = JOGADOR_o;

         if (ganhador != EMPATE)
            break;
            
        if (jogadas % 2 == 0)
        {
            jogador = JOGADOR_x;
        } else {
            jogador = JOGADOR_o;
        }
    }

    for (linha = 0; linha < QTD_linhas; linha += 1)
        {
            for (coluna = 0; coluna < QTD_colunas; coluna += 1)
                printf("%c ", tabuleiro[linha][coluna]);

            printf("\n");
        }

    return 0;
}
