#include <stdio.h>

// SOMAR DOIS ARRAYS E PASSA-LO PARA OUTRO ARRAY.

void somaV(int r[], int a[], int b[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        r[i] = a[i] + b[i];
    }
}

// int main() {
//     // 1. Criamos os arrays com tamanho 3
//     int vec1[3] = {10, 20, 30};
//     int vec2[3] = {1, 2, 3};
//     int resultado[3]; // Array vazio para guardar a soma

//     // 2. Chamamos a função passando o tamanho (3)
//     somaV(resultado, vec1, vec2, 3);

//     // 3. Imprimimos o resultado para verificar
//     printf("Resultado da soma:\n");
//     for(int i = 0; i < 3; i++) {
//         printf("%d ", resultado[i]); 
//     }
//     // Deve imprimir: 11 22 33

//     return 0;
// }

// SOMAR DUAS MATRIZES E PASSAR ESSA SOMA PARA OUTRA MATRIZ.

void somaM(int n, int m, int r[][m], int a[][m], int b[][m]) {
    int i, j; 
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}

// int main() {
//     int linhas = 2;
//     int colunas = 3;

//     // Matriz A (2x3)
//     int matA[2][3] = {
//         {1, 2, 3},
//         {4, 5, 6}
//     };

//     // Matriz B (2x3)
//     int matB[2][3] = {
//         {10, 10, 10},
//         {10, 10, 10}
//     };

//     int resultado[2][3]; // Onde vamos guardar a soma

//     // Chamada da função
//     somaM(linhas, colunas, resultado, matA, matB);

//     // Ciclo para imprimir o resultado no formato de tabela
//     printf("Matriz Resultado:\n");
//     for(int i = 0; i < linhas; i++) {
//         for(int j = 0; j < colunas; j++) {
//             printf("%d ", resultado[i][j]);
//         }
//         printf("\n"); // Salta uma linha quando acaba uma fila
//     }

//     return 0;
// }

// INDICA O TAMANHO DE UM ARRAY.
int sklen(char a[]){
    int i;
    for(i=0;a[i]!='\0';i++) {
    }
    return i;
}

// int main () {
//     char nome[] = "Ola";
//     int tamanho = sklen(nome);
//     printf("A palavra '%s' tem %d letra.\n", nome, tamanho);
//     return 0;
// }

// COPIA UM ARRAY PARA OUTRO.

char * strcopy (char dest[], char org[]) {
        int i;
        for(i=0;org[i]!='\0';i++) {
            dest[i] = org [i];
        }
        dest [i] = '\0';
        return 0;
}

// int main() {
//     char origem[] = "C e incrivel!";
//     char destino[50]; // Espaço suficiente para a cópia

//     strcopy(destino, origem);

//     printf("Origem: %s\n", origem);
//     printf("Destino: %s\n", destino); // Deve ser igual à origem

//     return 0;
// }

// JUNTA DOIS ARRAYS.

// char * strcat(char a[], char b[]) {
//     int ia, ib;

//     // 1. Achar o fim da string 'a'
//     for (ia = 0; a[ia] != '\0'; ia++) {
//         // Não fazemos nada, só queremos que o 'ia' chegue ao índice do '\0'
//     }

//     // 2. Copiar 'b' para o final de 'a'
//     for (ib = 0; b[ib] != '\0'; ib++) {
//         a[ia++] = b[ib]; // Avançamos no 'a' à medida que copiamos de 'b'
//     }

//     // 3. Fechar a string final
//     a[ia] = '\0';

//     return a;
// }

// ALTERNATIVA À FUNÇÃO STRCAT.

char * strcat (char a[], char b[]) {
        int fim_de_a = sklen(a);
        strcopy(&a[fim_de_a],b);
        return a;
        }

// int main() {
//     char saudacao[50] = "Ola "; // Tem de ter espaço extra para receber a outra!
//     char nome[] = "Mundo";

//     strcat(saudacao, nome);

//     printf("Frase colada: %s\n", saudacao); 
//     // Deve imprimir: Ola Mundo
    
//     return 0;
// }

// Diz se um determinado caracter é uma letra maiúscula. 
int toUpper (char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

// int main () { 
//     char teste = 'U';

//     if (toUpper(teste)) {
//         printf ("O caracter '%c' é maiúsculo.\n",teste);
//     } else {
//         printf ("O caracter '%c' não é maiúsculo.\n",teste);
//     }

//     return 0;
// }

// Uma função que testa se é vogal.

int eVogal(char v) {
    if(v=='a' || v=='e' || v=='i' || v=='o' || v=='u' || v=='A' || v=='E' || v== 'I' || v== 'O' || v== 'U') {
        return 1;
    } else {
        return 0;
    }
}

// ou

int eVogal1(char v) {
    char vogais[]= "AaEeIiOoUu";
    for(int i=0;i<10;i++) {
        if(v==vogais[i]) return 1;
        }
        return 0;
}

// int main () {
//     char teste = 'u';

//     if(eVogal1(teste)) {
//         printf("O caracter '%c' é uma vogal.\n",teste);
//     } else {
//         printf("O caracter '%c' não é uma vogal.\n",teste);
//     }
//     return 0;
// }

// Verifica se uma string está contida noutra string.
int strstr(char agulha[], char palheiro[]){
    int i,j;
    for(i=0;palheiro[i]!= '\0';i++) {
        for(j=0;agulha[i]!='\0' && agulha[j] == palheiro[i+j];j++) {
            if (agulha[j]=='\0') return (palheiro+1);
        }
    }
    return NULL;    
}

// int main () {
//     char agulha1[] = "Azul";
//     char palheiro1[] = "Céu Azul";

//     if(strstr(agulha1,palheiro1)) {
//         printf("A agulha: '%s' está contida no palheiro: '%s'.\n",agulha1,palheiro1);
//     } else {
//         printf("A agulha: '%s' não está contida no palheiro: '%s'.\n",agulha1,palheiro1);

//     }
//     return 0;
// }

// 
#define Max 10 

typedef struct s {
    int y[Max];     // Nome do array é 'y'
    int tamanho;    // Guarda quantos elementos tens lá dentro
} STACK;

// int main () {
//     STACK s1;
    
//     empty(&s1);
//     printf("Stack criada. Tamanho inicial: %d\n", s1.tamanho);

//     int resultado = push(45, &s1);
    
//     if (resultado == 0) {
//         printf("Push feito com sucesso! Novo tamanho: %d\n", s1.tamanho);
//         printf("Valor no topo: %d\n", s1.y[s1.tamanho - 1]);
//     } else {
//         printf("Erro: Stack cheia!\n");
//     }

//     return 0;
// }

void empty(STACK *s) {
    s->tamanho = 0;   // Define que a stack está vazia
}

// Verifica se posso colocar um determinado valor na stack, se a stack estiver cheia nao posso. Se não estiver cheia, coloca o na stack.
int push(int x, STACK *s) {
    int r = 0;
    // Verifica se há espaço
    if(s->tamanho < Max) {
        s->y[s->tamanho++] = x;    
    } else {
        r = 1;                // Stack cheia!
    }
    return r;
}

// Verifica se um dado elemento pertence a um array.
int elem (int x,int v[],int N) {
    for(int i=0;i<N;i++) {
        if (x==v[i]) {
            return i;
        } 
    }
    return (-1);
}

// int main () {
//     int elemento = 4;
//     int lista[]  = {7,7,7,32,0,3,0,1,34,1,6,23,4};
//     int tamanho  = 13;

//     int resultado = elem(elemento,lista,tamanho);

//     if (resultado != -1) {
//         printf("O valor %d foi encontrado na posicao: %d\n", elemento, resultado);
//     } else {
//         printf("O valor %d nao foi encontrado no array.\n", elemento);
//     }
//     return 0;
// }

// Procura um elemento, num array ordenado.
int procura (int x, int v[], int N){
    int i;
    for(i=0;i<N && v[i]<=x;i++) {
        if (x==v[i]) return i;
    }
    return (-1);
}

// int main () {
//     int x = 1000;
//     int lista[] = {1,2,3,8,80,90,100,1000,1000000};
//     int tamanho = 9;
//     int resultado = procura(x,lista,tamanho);

//     if (resultado != -1) {
//         printf("O elemento '%d' está na lista.\n",x);
//     } else {
//         printf("O elemento '%d' não está na lista.\n",x);
//     }
//     return 0;
// }

// 