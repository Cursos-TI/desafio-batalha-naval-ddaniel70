#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
               // variaveis 

    int tabuleiro[10][10];                  // variavel chamada tabuleiro onde e uma matriz bidimensional 10 por 10, represetando o tabuleiro
    int navio_horizontal[3] = {3, 3, 3};   // vetor que representa o navio horizontal
    int navio_vertical[3] = {3, 3, 3};    // vetor que representa o navio vertical

            // variaveis de cordenadas do navios 
    int linha_navio1 = 2, coluna_navio1 = 4;          // cordenados navio horizontal 
    int linha_navio2 = 5, coluna_navio2 = 1;          // cordenadas navio vertical 
    int permissao = 1;                                   // variavel que determina se o navio pode ou nao usar aquela casa
    
            // atenção lembre que os indices começam com 0

         // iniciar todos os elementos da matriz tabuleiro com 0, representando a água 

    for (int linha = 0; linha < 10; linha++)                     // esse loop externo controla as linhas 
    {
        for (int coluna = 0; coluna < 10; coluna++)            // esse loop interno controla as colunas
        {
            tabuleiro[linha][coluna] = 0;                    // quando linha for 0 esse loop percorre de os elementos 
        }                                                   // da linha 0, e das colunas 0 ate a 9, [0][0] = a 0, [0][1]= 0 e assim vai 
    }

            //cada navio ocupa 3 posições e cada posição e representada pelo numero 3

           // navio horizontal
        
         // logica simples de verificar se o navio nao sobressai e nao vai ocupar casas que ja estao coupadas

       // aqui ele verifica que se a posição do navio nao e maior que 7 , pois o navio ocupa 3 casas, exemplo a 7 e mais duas totalizando 9 o maximo , pois o navio e horizontal
    
    if ((linha_navio1 <= 9 && coluna_navio1 <= 7) && (linha_navio1 >= 0 && coluna_navio1 >= 0)) // aqui ele verifica se o navio nao vai sobressair o tabuleiro
    {   
        for (int i = 0; i < 3; i++)                                        // aqui ele roda o if else para garantir que as casas que o navio vai ocupar casas que estao ocupadas por outro
        {
          if (tabuleiro[linha_navio1][coluna_navio1 + i] != 0)           // verifica se as casas estao ocupadas
          {
            permissao = 0;                                             // se as casas tiverem ocupadas a variavel ganha valor 0
            printf("Essa posição esta ocupada tente novamente \n");   // imprime que tem uma casa ocupada
            break;                                                   // evita verificar e imprimir mais vezes desnecessariamente 
          }
        }
    } else
         {
           printf("Essa posição do Navio sobressai o tabuleiro!!! tente novamente \n");     // se o navio se sobressair do tabuleiro ele imprime essa mensagem
         }

        // aqui iremos colocar o valor do navio do vetor na matriz

    if (permissao == 1)                                   // se tiver as casas estiver livres, atribuimis as elas o valor do navio com o loop, 3 casas com numero 3
    {
        for (int i = 0; i < 3; i++)                      // loop for para o navio horizontal, lembrando que o navio ocupa 3 espaços 
        {                                               // iremos colocar ele na segunda linha nas colunas 4 5 6 , lembrando que os indices começam em 0
            tabuleiro[linha_navio1][coluna_navio1 + i] = navio_horizontal[i]; // pega o valor do vetor e atrbui na matriz na posição desejada
        }
    } 

       // navio vertical

         // aqui verificamos se linha 5 6 e 7 esta livre com && , usei uma lógica simples de verificar
        // verificamos se o navio nao vai sair da tabuleiro, aqui ele ficara na linha 5 6 e 7 , ent verificamos se a linha 5 mais duas casas nao passa limite do tabuleiro
       // verificamos a linha ate <= 7 pois e adicionado mais duas casas ao posicionar o navio , isso para sobressair o limite das linhas que e ate 9
   
    if ((linha_navio2 <= 7 && coluna_navio2 <= 9) && (linha_navio2 >= 0 && coluna_navio2 >= 0)) // aqui ele verifica se o navio nao vai sobressair o tabuleiro
    {   
        permissao = 1;                          // aqui damos o valor 1 a variavel para ela esquecer o valor que foi atribuido a ela no teste anterior
        for (int i = 0; i < 3; i++)            // aqui ele roda o if else para garantir que as casas que o navio vai ocupar casas que estao ocupadas por outro
        {
          if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0)    // verifica se as casas estao ocupadas
          {
            permissao = 0;                                             // se as casas tiverem ocupadas a variavel ganha valor 0
            printf("Essa posição esta ocupada tente novamente \n");   // imprime que tem uma casa ocupada
            break;                                                   // evita verificar e imprimir mais vezes desnecessariamente 
          }
        }
    } else
         {
           printf("Essa posição do Navio sobressai o tabuleiro!!! tente novamente \n");  // imprime a mensagem que o navio sobressaiu o tabuleiro 
         }

         // aqui iremos colocar o valor do navio vertical vetor na matriz 

      if (permissao == 1)                                      // se a variavel tiver valor 1 as casas estao livre o loop roda
    {
        for (int i = 0; i < 3; i++)                          // loop for para o navio horizontal, lembrando que o navio ocupa 3 espaços 
            {                                               // iremos colocar ele na segunda linha nas colunas 4 5 6 , lembrando que os indices começam em 0
                tabuleiro[linha_navio2 + i][coluna_navio2] = navio_vertical[i]; // pega o valor do vetor e atrbui na matriz na posição desejada
            }
    } 

        // imprimir o tabuleiro
   
        // iremos imprimir as letras que ficaram em cima de A a J para representar as colunas
        
    printf("Tabuleiro Batalha Naval \n");                  // imprime o cabeçalho do jogo 

    printf("   ");                                        // para empurras as letras mais a direita, deixando elas devidamente 
        for (char letras = 'A'; letras <= 'J'; letras++) // encima da coluna e não do marcador de linhas
        {
            printf(" %c ", letras);                     // espaço antes do %c para as letras nao ficare agrupadas e depois
        }
    
    printf("\n");                                     // pular a linha

        // iremos imprimir os números que ficam na lateral de 1 a 1o para identificar as linhas
        // junto iremos imprimir toda a matriz
    
    for (int linha = 0; linha < 10; linha++)            // controla e imprime os números das linhas 
    {
        printf("%2d", linha + 1);                       // numeros da linha , usamos %2d para que tenha duas casas decimais e número 10 n empurre pra frente os outros 
        for (int coluna = 0; coluna < 10; coluna++)    // colocamos  linha +1 para exibir de 1 a 10
        {                                              // controla e imprime as colunas daquela linha
            printf(" %d ", tabuleiro[linha][coluna]);  // imprime  a linha e todas as colunas daquela linha , tem um espaço depois do %d para nao deixar os numeros juntos e antes para deixar eles alinhados com as letras
        }
        printf("\n");                                 // aqui pulamos a linha que estamos e vamos para a proxima
    }
    
    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


