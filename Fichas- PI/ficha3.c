#include <stdio.h> 

// Protótipos de todas as funções para evitar erros de declaração implícita
void swapM (int *x, int *y);
void swap (int v[], int i, int j);
int soma (int v[], int N);
int maximum (int v[], int N, int *m);
void pascal (int v[], int N);
void print_spaces(int n);
void dumpV(int v[], int n);
void inverteArray (int v[], int N);

int main () {
    // 1. Testar o SWAP de variáveis simples
    int x = 3, y = 5;
    swapM (&x, &y);
    printf ("%d %d\n", x, y);

    int oMeuArray[] = {10, 20, 30, 40, 50};
    int tamanho = 5;

    // 2. Testar a SOMA
    int resultadoSoma = soma(oMeuArray, tamanho);
    printf("A soma de todos os elementos e: %d\n", resultadoSoma);
    // (Dica: 10+20+30+40+50 deve dar 150)

    // 3. Testar o SWAP (vamos trocar o 10 pelo 50)
    //printf("\nAntes do swap: posicao 0 = %d, posicao 4 = %d\n", oMeuArray[0], oMeuArray[4]);
    
    //swap(oMeuArray, 0, 4);
    
    //printf("Depois do swap: posicao 0 = %d, posicao 4 = %d\n", oMeuArray[0], oMeuArray[4]);

    int arrayComMaximo;

    int resultadoMax = maximum(oMeuArray,tamanho, &arrayComMaximo);
    printf("O maximo do array em questao é: %d\n",resultadoMax);
    printf("O maximo (via ponteiro) e: %d\n", arrayComMaximo);

    int N = 5;
    int v[N];
    for (int i=1;i<=N;i++) {
        pascal(v,i);
        print_spaces(N-i);
        dumpV(v,i);
    }

    // 6. Testar o InverteArray
    inverteArray(oMeuArray,tamanho); 
    printf("A inversao do respetivo array é: ");
    for(int i = 0; i < tamanho; i++) printf("%d ", oMeuArray[i]);
    printf("\n"); 

    return 0;
}

// Defina uma funcao void que troca o valor de duas variaveis.
void swapM (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Defina uma funcao que troca o valor das posicoes i e j do vetor v. 
void swap (int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp; 
}

// Calcula a soma dos elementos de um vetor v com N inteiros.
int soma (int v[], int N){
    int total = 0;
    for(int i= 0;i<N;i++){
        total += v[i];
    }
    return total;
}

// Que coloca em *m o maior dos elementos do vector v.
int maximum (int v[], int N, int *m) {
    *m = v[0];
    for(int i=1;i<N;i++){
        if(v[i] > *m) {
            *m = v[i];
        }
    }
    return *m;
}
    
// Preenche o vector v com a N-esima linha do triangulo de Pascal.
// Pede p dar print de uma linha.
void pascal (int v[], int N) {
    if (N <= 0) return; 
    v[0] = 1;
    for(int i=1;i<N;i++) {
            v[i] = 1;
            for(int j=i;j>0;j--) {
            v[j] = v[j] + v[j-1];
            }
    }
}

// Funcao q escreve no ecran as N primeiras linhas do triangulo.
// Pede pa dar print de todas as linhas.
// Imprime espaços para alinhar o triângulo à direita
void print_spaces(int n) {
    for (int i = 0; i < n; i++) {
        printf("  "); // Dois espaços costumam alinhar melhor que um
    }
}

// Imprime os elementos do array que pertencem à linha atual
void dumpV(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d   ", v[i]); // Imprime o número e um espaço entre eles
    }
    printf("\n"); // Salta para a próxima linha do triângulo
}

// tentar fazer isto de forma recursiva e ver isto em casa.
// Inverte um array.
void inverteArray (int v[], int N) {
    for (int i = 0; i < N / 2; i++) {
        swap(v, i, N - 1 - i); 
    }
}

void quadrados (int q[], int N) {
    q[0] = 0; // O primeiro quadrado é sempre 0
    for (int i = 0; i < N - 1; i++) {
        q[i+1] = q[i] + (2 * i + 1);
    }
}   