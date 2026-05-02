#include <stdio.h>
#include <stdlib.h>

// --- PROTÓTIPOS (Para o main saber que as funções existem abaixo) ---
void swap(int v[], int pos1, int pos2);
int tamanhoString (char *s);
int contaVogais (char *s);

// --- AS TUAS FUNÇÕES (EXATAMENTE COMO ESTAVAM) ---

int contaVogais (char *s) {
    int total= 0;
    for(int i=0;s[i]!='\0';i++) {
        if(s[i]=='a' || s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U') {
            total++;
        } 
    }
    return total;
}

int menosFreq (int v[], int N) {
    int res = v[0], min_f = N, atual_f = 1;
    for (int i = 1; i < N; i++) {
        if (v[i] == v[i - 1]) atual_f++;
        else {
            if (atual_f < min_f) {
                min_f = atual_f;
                res = v[i - 1];
            }
            atual_f = 1;
        }
    }
    if (atual_f < min_f) res = v[N - 1];
    return res;
}

int contaVogaisRep (char *s) { 
    int total = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if ((s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || 
             s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || 
             s[i]=='u' || s[i]=='U') 
            && (s[i] == s[i+1])) { 
            
            total++;
        }
    }
    return total;
}

int duplicaVogais (char *s) {
    int v = contaVogais(s);     // Quantas vogais temos?
    int tam = tamanhoString(s); // Qual o tamanho original?
    
    int i = tam;     // O 'i' começa no '\0' original
    int j = tam + v; // O 'j' começa no NOVO local do '\0'
    
    // O ciclo vai de trás para a frente até chegar ao início da string
    while (i >= 0) {
        
        // Pergunta: A letra atual s[i] é uma vogal?
        if (s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || 
            s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || 
            s[i]=='u' || s[i]=='U') {
            
            s[j] = s[i]; // Escreve a vogal na posição j
            j--;         // Anda uma casa para trás com o escritor
            s[j] = s[i]; // Escreve a mesma vogal de novo (DUPLICOU!)
            // O j vai diminuir mais uma vez ali em baixo
        } 
        else {
            s[j] = s[i]; // Se for consoante ou o '\0', apenas copia
        }

        i--; // O leitor anda sempre uma casa para trás
        j--; // O escritor anda sempre (pelo menos) uma casa para trás
    }

    return v; // Devolvemos o número de caracteres acrescentados
}

int tamanhoString (char *s) {
    int i = 0;
    while(s[i]!='\0') i++;
    return i;
}

int ordenado (int v[], int N) {
    if (N<2) return 1;
    for(int i=0;i<N-1;i++) {
        if(v[i]>v[i+1]) {
            return 0;
        }
    }
    return 1;
}

void merge (int a[], int na, int b[], int nb, int r[]) {
    int i=0;
    int j=0;
    int k=0;
    while(i<na&&j<nb) {
        if(a[i]<b[j]) {
            r[k]=a[i];
            i++;
        } else {
            r[k]=b[j];
            j++;
        }
        k++;
    }
    // Nota: Para o merge ficar completo, faltariam os whiles de limpeza 
    // que discutimos antes, mas mantive como enviaste!
}

int partition (int v[], int N, int x) {
    int i;
    int j=0;
    for(i=0;i<N;i++) {
        if (v[i]<=x) {
            swap(v,i,j);
            j++;
        }
    }
    return j;
}

void swap(int v[],int pos1,int pos2) {
    int temp= v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

// --- MAIN ÚNICO PARA TESTES ---

int main() {
    int opcao;
    printf("--- TESTES FICHA 4 ---\n");
    printf("1. contaVogais\n2. menosFreq\n3. contaVogaisRep\n4. duplicaVogais\n");
    printf("5. ordenado\n6. merge\n7. partition\nEscolha: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1: {
            char s[] = "Ola Mundo";
            printf("Vogais em '%s': %d\n", s, contaVogais(s));
            break;
        }
        case 2: {
            int v[] = {10, 10, 20, 30, 30};
            printf("Menos frequente: %d\n", menosFreq(v, 5));
            break;
        }
        case 3: {
            char s[] = "Aaeiouu";
            printf("Vogais repetidas seguidas: %d\n", contaVogaisRep(s));
            break;
        }
        case 4: {
            char s[50] = "Ola"; // Espaço extra para duplicar
            duplicaVogais(s);
            printf("Duplicado: %s\n", s);
            break;
        }
        case 5: {
            int v[] = {1, 2, 5, 4};
            printf("Ordenado? %d\n", ordenado(v, 4));
            break;
        }
        case 6: {
            int a[]={1,5}, b[]={2,4}, r[4];
            merge(a, 2, b, 2, r);
            printf("Merge: %d %d %d %d\n", r[0], r[1], r[2], r[3]);
            break;
        }
        case 7: {
            int v[] = {10, 2, 5, 20, 1};
            int pos = partition(v, 5, 6);
            printf("Partition em 6. Elementos <= 6: %d\nArray: ", pos);
            for(int i=0; i<5; i++) printf("%d ", v[i]);
            printf("\n");
            break;
        }
        default: printf("Opcao invalida.\n");
    }
    return 0;
}