#include <stdio.h>

#define linhas 10            // define a quantidade de linhas da matriz
#define colunas 10          // define a quantidade de colunas da matriz
#define Tamanho_navios 3   // define o tamanho dos navios

int main() {

      // variáveis matrizes e vetores
  
     // matrizes

    int tabuleiro[linhas][colunas];          // define a matriz tabuleiro 
    int permissao = 1;                      // variavel que determina se o navio pode ou nao usar aquela casa

     // vetores navios vertical e horizontal
    int navio_horizontal[Tamanho_navios] = {4, 5 , 6};    // vetor do navio horizontal, colunas que o navio horizontal vai ocupar
    int navio_vertical[Tamanho_navios] = {5, 6, 7};      // vetor do navio vertical, com as linhas que ele vai ocupar 
 
       // vetores 1 navio diagonal
    int diagonal_linhas_1 [Tamanho_navios] = {9, 8, 7};         // vetor linhas navio 1 diagonal com as posições que ele vai ocupar
    int diagonal_colunas_1 [Tamanho_navios] = {0, 1, 2};       // vetor colunas navio 1 diagonal com as posições que ele vai oucupar

       // vetores 2 navio diagonal
    int diagonal_linhas_2 [Tamanho_navios] = {0, 1, 2};        // vetor linhas navio 2 diagonal
    int diagonal_colunas_2 [Tamanho_navios] = {0,1, 2};      // vetor colunas navio 2 diagonal


    // iniciar todos os elementos da matriz com 0 representando agua 

     for (int linha = 0; linha < 10; linha++)                     // esse loop externo controla as linhas 
    {
        for (int coluna = 0; coluna < 10; coluna++)            // esse loop interno controla as colunas
        {
            tabuleiro[linha][coluna] = 0;                    // quando linha for 0 esse loop percorre de os elementos 
        }                                                   
    }

        // verificar se o navio cabe no tabuleiro e se ele nao vai sobrepor outro
       // apos tudo verificado ele confere se esta livre e posicona o navio

     // verificar navio horizontal
    
     for (int i = 0; i < 3; i++)
    {
        if ((navio_vertical[i] > colunas) || (tabuleiro[2][navio_horizontal[i]] != 0))
        {
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break; 
        }   
    }

    // posicionar o navio horizontal

    if (permissao == 1)                                   // casas livres atribuimos o valor 3 em cada uma dela
    {                                                     // iremos colocar ele na linha 2, colunas 4, 5, 6 indices comecam com 0
        for (int i = 0; i < Tamanho_navios; i++)         // loop for para o navio horizontal, lembrando que o navio ocupa 3 espaços 
        {                                             
            tabuleiro[2][navio_horizontal[i]] = Tamanho_navios;     // atribui o valor do navio 
        }
    } 


    // verificar o navio vertical 

    permissao = 1;  // reiniciando a variavel

    for (int i = 0 ; i < Tamanho_navios; i++)   
    {
        if ((navio_vertical[i] > linhas) || (tabuleiro[navio_vertical[i]][4] != 0))
       {
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break; 
        }   
    }
 
    // apos tudo verificado ele confere se esta livre e posicona o navio vertical

    if (permissao == 1)                                   // casas livres atribuimos o valor 3 em cada uma dela
    {
        for (int i = 0; i < Tamanho_navios; i++)         // loop for para o navio horizontal, lembrando que o navio ocupa 3 espaços 
        {                                                // iremos colocar ele na segunda linha 5, 6, 7, e na coluna 4 os indices começam em 0
            tabuleiro[navio_vertical[i]][4] = Tamanho_navios;     // atribui o valor do navio 
        }
    } 

    
    // verifica o navio diagonal 1 , verifica colunas, linhas e posições para nao sobrepor
    
    permissao = 1;  // reinicio a variavel para verificar o proximo navio 
    
    for (int i = 0 ; i < Tamanho_navios; i++)   
    {
        if (( (diagonal_linhas_1[i] > linhas) || (diagonal_colunas_1[i] > colunas)) || (tabuleiro[diagonal_linhas_1[i]][diagonal_colunas_1[i]] != 0))
        {
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break;
        }    
    }

   // Posiciona navio diagonal 1 começando em (9,0)
  // apos tudo verificado ele confere se esta livre e posicona o navio horizontal

    if (permissao == 1)                                // casas livres atribuimos o valor 3 em cada uma dela
    {
        for (int i = 0; i < Tamanho_navios; i++) 
        {
            tabuleiro[diagonal_linhas_1[i]][diagonal_colunas_1[i]] = Tamanho_navios; // pega as posições que ele vai ficar no vetor e atribui valor
        }
    } 

  
     // verifica o navio diagonal 2

    permissao = 1;  // reinicio a variavel para verificar o proximo navio 

    for (int i = 0 ; i < Tamanho_navios; i++)   
    {
        if (( (diagonal_linhas_2[i] > linhas) || (diagonal_colunas_2[i] > colunas)) || (tabuleiro[diagonal_linhas_2[i]][diagonal_colunas_2[i]] != 0))
        {
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break;
        }    
    }

    // Posiciona navio diagonal 2  começando em (0,0)
    // apos tudo verificado ele confere se esta livre e posicona o navio horizontal

    if (permissao == 1)                                // casas livres atribuimos o valor 3 em cada uma dela
    {
        for (int i = 0; i < Tamanho_navios; i++) 
        {
            tabuleiro[diagonal_linhas_2[i]][diagonal_colunas_2[i]] = Tamanho_navios; // pega as posições que ele vai ficar no vetor e atribui valor
        }
    } 


  // iremos imprimir as letras que ficaram em cima de A a J para representar as colunas
        
    printf("Tabuleiro Batalha Naval \n");                  // imprime o cabeçalho do jogo 

    printf("  ");                                        // para empurras as letras mais a direita, deixando elas devidamente 
        for (char letras = 'A'; letras <= 'J'; letras++) // encima da coluna e não do marcador de linhas
        {
            printf(" %c ", letras);                     // espaço antes do %c para as letras nao ficare agrupadas e depois
        }
    
    printf("\n"); 

         // iremos imprimir os números que ficam na lateral de 1 a 1o para identificar as linhas
        // junto iremos imprimir toda a matriz
    
    for (int linha = 0; linha < linhas; linha++)             // controla e imprime os números das linhas 
    {                                                   // numeros da linha , usamos %2d para ter duas casas decimais e número 10 n empurre pra frente os outros 
        printf("%2d", linha + 1);                      //colocamos  linha +1 para exibir de 1 a 10
        for (int coluna = 0; coluna < colunas; coluna++)    
        {                                              
            printf(" %d ", tabuleiro[linha][coluna]);   //tem um espaço depois do %d para nao deixar os numeros juntos 
        }                                              // tem um espaço antes para deixar eles alinhados com as letras
        printf("\n");                                 // aqui pulamos a linha que estamos e vamos para a proxima
    }

    return 0;
}
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


