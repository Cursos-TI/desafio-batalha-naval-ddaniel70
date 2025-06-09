#include <stdio.h>
#include <stdlib.h>  // biblioteca do abs, abslute valor, retorna o valor sem sinal de um número inteiro

#define linhas 10                // define a quantidade de linhas da matriz
#define colunas 10              // define a quantidade de colunas da matriz
#define Tamanho_navios 3       // define o tamanho dos navios
#define tamanho_habilidades 5 // define o tamanho da habilidade
      
     // função recursiva void onde ela tem nenhum retorno
    
     // função cruz 

void preencher_cruz(int matriz[tamanho_habilidades][tamanho_habilidades]){  // função void nao retorna nada
    for (int i = 0; i < tamanho_habilidades; i++){                         // percorremos a matriz 
        for (int j = 0; j < tamanho_habilidades; j++){        
            if (i == tamanho_habilidades /2 || j == tamanho_habilidades /2){    // verificamos se estamos ma linha central ou na coluna central
                matriz[i][j] = 1;                                              // marca os elementos centrais com o valor 1
            } else{
                matriz[i][j] = 0;                                              // marca os elementos que não saõ centrais com 0 
            }
        }
    }
}

    // função cone 

void preencher_Cone(int matriz[tamanho_habilidades][tamanho_habilidades]){ // função void com a matriz
    for (int i = 0; i <= tamanho_habilidades / 2; i++){                         // percorremos as linhas e colunas
        for (int j = 0; j < tamanho_habilidades; j++){
            if (j >= tamanho_habilidades/2 - i && j <= tamanho_habilidades/2 + i){  // limito até metade do tamanho da matriz para nao posicionar mais que o desejado
                matriz[i][j] = 1;                                         // atribuo o valor 1 parao local da habilidade
            } else{                                                       
                matriz[i][j] = 0;                                        // atribui zero ao restante dos valores
            }
        }
    }
}

    // função octaedro

void preencher_octaedro(int matriz[tamanho_habilidades][tamanho_habilidades]){           // função void     
    for (int i = 0; i < tamanho_habilidades; i++){                                   // percorremos linhas e colunas 
        for (int j = 0; j < tamanho_habilidades; j++){
            if (abs (i - tamanho_habilidades /2 ) +  abs( j - tamanho_habilidades /2) <= tamanho_habilidades /2){  // usamos o abs para transforma os valores negativos em positivos
                matriz[i][j] = 1;         // atribui o valor 1 ao local que tera a habilidade, no if calculamos a distancia entre um elemento ate o centro da matriz
            } else{
                matriz[i][j] = 0;        // atribui 0 ao restante dos valores
            }
        }  
    }
}
   
    // função para verificar e aplicar todas as habilidades 

void aplicarHabilidade(int tabuleiro[linhas][colunas], int habilidade[tamanho_habilidades][tamanho_habilidades], int origem_linha, int origem_coluna){     // aqui temos as matrizes do tabuleiro da habilidade e ciramos a colunas e linhas para armazenar as cordenadas
    for (int i = 0; i < tamanho_habilidades; i++){            
        for (int j = 0; j < tamanho_habilidades; j++){            // percorremos a matriz habilidade em busca dos 0 e 1 
            int li = origem_linha + i - tamanho_habilidades / 2;  // aplicar a habilidade no centro das cordenadas que escolhi tanto na linha quanto na coluna 
            int col = origem_coluna + j - tamanho_habilidades / 2;
            if (li >= 0 && li < linhas && col >= 0 && col < colunas){     // aqui verificamos se a habilidade nao vai sobressair o tabuleiro 
                if (habilidade[i][j] == 1 && tabuleiro[li][col] != 3 && tabuleiro[li][col] != 5 ){    // aqui verificamos se a habilidade nao vai sobrepor o navio ou outra habilidade
                    tabuleiro[li][col] = 5;                               // Marca área de habilidade com 5
                }
            }
        }
    }
}


int main() {

      // variáveis matrizes e vetores

      // atençao lembre que os índices começam com 0
  
     // matrizes

    int tabuleiro[linhas][colunas];          // define a matriz tabuleiro 
    int permissao = 1;                      // variavel que determina se o navio pode ou nao usar aquela casa

     // vetores navios vertical e horizontal
    int navio_horizontal[Tamanho_navios] = {2, 3 , 4};    // vetor do navio horizontal, colunas que o navio horizontal vai ocupar
    int navio_vertical[Tamanho_navios] = {6, 7, 8};      // vetor do navio vertical, com as linhas que ele vai ocupar 
 
       // vetores 1 navio diagonal
    int diagonal_linhas_1 [Tamanho_navios] = {9, 8, 7};         // vetor linhas navio 1 diagonal com as posições que ele vai ocupar
    int diagonal_colunas_1 [Tamanho_navios] = {0, 1, 2};       // vetor colunas navio 1 diagonal com as posições que ele vai oucupar

       // vetores 2 navio diagonal
    int diagonal_linhas_2 [Tamanho_navios] = {0, 1, 2};        // vetor linhas navio 2 diagonal
    int diagonal_colunas_2 [Tamanho_navios] = {0,1, 2};      // vetor colunas navio 2 diagonal

        // matrizes onde armazenam o formato de cada habilidade com 0 e 1
    int cruz[tamanho_habilidades][tamanho_habilidades];                 // armazenamos o formato da cruz
    int cone[tamanho_habilidades][tamanho_habilidades];                 // armazenamos o formato do cone
    int octaedro[tamanho_habilidades][tamanho_habilidades];             // armazenamos o formato do octaedro



    // iniciar todos os elementos da matriz com 0 representando agua 

     for (int linha = 0; linha < 10; linha++){                    // esse loop externo controla as linhas 
        for (int coluna = 0; coluna < 10; coluna++){            // esse loop interno controla as colunas
            tabuleiro[linha][coluna] = 0;                    // quando linha for 0 esse loop percorre de os elementos 
        }                                                   
    }

        // verificar se o navio cabe no tabuleiro e se ele nao vai sobrepor outro
       // apos tudo verificado ele confere se esta livre e posicona o navio

     // verificar navio horizontal
    
     for (int i = 0; i < 3; i++){
        if ((navio_vertical[i] > colunas) || (tabuleiro[2][navio_horizontal[i]] != 0)){
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break; 
        }   
    }

    // posicionar o navio horizontal

    if (permissao == 1){                                 // casas livres atribuimos o valor 3 em cada uma dela                                                   
        for (int i = 0; i < Tamanho_navios; i++){         // loop for para o navio horizontal, lembrando que o navio ocupa 3 espaços                                              
            tabuleiro[0][navio_horizontal[i]] = Tamanho_navios;     // atribui o valor do navio 
        }
    } 

    permissao = 1;  // reiniciando a variavel

    for (int i = 0 ; i < Tamanho_navios; i++){   
        if ((navio_vertical[i] > linhas) || (tabuleiro[navio_vertical[i]][4] != 0)){
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break; 
        }   
    }
 
    // apos tudo verificado ele confere se esta livre e posicona o navio vertical

    if (permissao == 1){                                   // casas livres atribuimos o valor 3 em cada uma dela
        for (int i = 0; i < Tamanho_navios; i++){         // loop for para o navio horizontal, lembrando que o navio ocupa 3 espaços                                          
            tabuleiro[navio_vertical[i]][4] = Tamanho_navios;     // atribui o valor do navio 
        }
    } 

    
    // verifica o navio diagonal 1 , verifica colunas, linhas e posições para nao sobrepor
    
    permissao = 1;  // reinicio a variavel para verificar o proximo navio 
    
    for (int i = 0 ; i < Tamanho_navios; i++){   
        if (( (diagonal_linhas_1[i] > linhas) || (diagonal_colunas_1[i] > colunas)) || (tabuleiro[diagonal_linhas_1[i]][diagonal_colunas_1[i]] != 0)){
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break;
        }    
    }

   // Posiciona navio diagonal 1 começando em (9,0)
  // apos tudo verificado ele confere se esta livre e posicona o navio horizontal

    if (permissao == 1){                                // casas livres atribuimos o valor 3 em cada uma dela
        for (int i = 0; i < Tamanho_navios; i++){ 
            tabuleiro[diagonal_linhas_1[i]][diagonal_colunas_1[i]] = Tamanho_navios; // pega as posições que ele vai ficar no vetor e atribui valor
        }
    } 

  
     // verifica o navio diagonal 2

    permissao = 1;  // reinicio a variavel para verificar o proximo navio 

    for (int i = 0 ; i < Tamanho_navios; i++){   
        if (( (diagonal_linhas_2[i] > linhas) || (diagonal_colunas_2[i] > colunas)) || (tabuleiro[diagonal_linhas_2[i]][diagonal_colunas_2[i]] != 0)){
            printf(" O navio sobressai o tabuleiro ou essas cordenadas ja estao ocupadas \n");
            permissao = 0;       // caso o navio sobressai ou sobreponha a permissao e negada
            break;
        }    
    }

    // Posiciona navio diagonal 2  começando em (0,0)
    // apos tudo verificado ele confere se esta livre e posicona o navio horizontal

    if (permissao == 1){                                // casas livres atribuimos o valor 3 em cada uma dela
        for (int i = 0; i < Tamanho_navios; i++){
            tabuleiro[diagonal_linhas_2[i]][diagonal_colunas_2[i]] = Tamanho_navios; // pega as posições que ele vai ficar no vetor e atribui valor
        }
    } 

      // construir as habilidades definir o formato e armazenar cada uma na sua matriz

    preencher_cruz(cruz);
    preencher_Cone(cone);
    preencher_octaedro(octaedro);

        // aplicar habilidades 

    aplicarHabilidade (tabuleiro, cruz, 7, 7);     // aplicamos todas as habilidades cada uma em suas cordenadas
    aplicarHabilidade (tabuleiro, cone, 5, 2); 
    aplicarHabilidade (tabuleiro, octaedro, 2, 6);

  // iremos imprimir as letras que ficaram em cima de A a J para representar as colunas
        
    printf("Tabuleiro Batalha Naval \n");                  // imprime o cabeçalho do jogo 

    printf("  ");                                        // para empurras as letras mais a direita, deixando elas devidamente 
    for (char letras = 'A'; letras <= 'J'; letras++){ // encima da coluna e não do marcador de linhas
            printf(" %c ", letras);                     // espaço antes do %c para as letras nao ficare agrupadas e depois
        }
    
    printf("\n"); 

         // iremos imprimir os números que ficam na lateral de 1 a 1o para identificar as linhas
        // junto iremos imprimir toda a matriz
    
    for (int linha = 0; linha < linhas; linha++){             // controla e imprime os números das linhas 
        printf("%2d", linha + 1);                           //colocamos  linha +1 para exibir de 1 a 10, usamos %2d para duas casas decimais
        for (int coluna = 0; coluna < colunas; coluna++){                                                  
            printf(" %d ", tabuleiro[linha][coluna]);   //tem um espaço depois do %d para nao deixar os numeros juntos 
        }                                              // tem um espaço antes para deixar eles alinhados com as letras
        printf("\n");                                 // aqui pulamos a linha que estamos e vamos para a proxima
    }

    return 0;
}