#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- DEFINIÇÕES ---
typedef struct posicao {
    int x, y;
} Posicao;

// --- FUNÇÕES ---

int remRep (char x[]) {
    int i=1;
    int j=1;
    for(i=0;x[i]!='\0';i++) {
        if(x[i]!=x[i-1]) {
            x[j]=x[i];
            j++;
        }
    }
    x[j] = '\0';
    return j;
}

void insere (int v[], int N, int x) {
    int i;
    while(i>=0 && v[i]>x){
        v[i+1]= v[i];
        i--;
    }
    v[i+1] = x;
}

int crescente (int a[], int i, int j) {
    int k;
    for(k=i;k<j;k++) {
        if(a[k]>a[k+1]) {
            return 0;
        }
    }
    return 1;
}

int maisFreq (int v[], int N){
    int k= v[0];
    int conta_atual= 1; // contagem de repetições.
    int max_conta= 1; // máximo de repetições. 
    for(int i=1;i<N;i++) {
        if(v[i] == v[i-1]) {
            conta_atual++;
        } else {
            if(conta_atual>max_conta) {
                max_conta = conta_atual;
                k = v[i-1];
            }
            conta_atual = 1;

        }
    }
    if(conta_atual>max_conta) {
        k=v[N-1];
    }
    return k;
}

int maisCentral (Posicao pos[], int N) {
    int vencedor = 0; // Começamos por assumir que o primeiro (0) é o melhor.
    int i;
    int dist_min = (pos[0].x * pos[0].x) + (pos[0].y * pos[0].y); // Calculamos a distância do primeiro para ter um ponto de comparação.
    for(i=0;i<N;i++) {
        int dist_atual = (pos[i].x * pos[i].x) + (pos[i].y * pos[i].y);
        if(dist_atual < dist_min) {
            dist_atual = dist_min; // O novo recorde de distância é este.
            vencedor= i; // O novo índice vencedor é o i.
        }
    }
    return vencedor;
}

int contaVogais1 (char s[]) {
    int contagem = 0;
    int i;
    for(i=0;s[i]!='\n';i++) {
        if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U') {
          contagem ++;
        }
    }
    return contagem;
}

int contida (char a[], char b[]) {
    int i; // indice q percorre a primeira string.
    int j; // indice q percorre a segunda string.
    int encontrou;
    for(i=0;i!='\0';i++){
        encontrou=0;
        for(j=0;j!='\0';j++) {
            if(a[i]==b[j]) {
                encontrou=1;
                break;
            }
        }
        if(encontrou==0) {
            return 0;
        }
    }
    return 1;
}

void merge1 (int r[], int a[], int na, int b[], int nb) {
    int i=0;
    int j=0;
    int k=0;

    while(i<na && j<nb) {
        if(a[i]<b[j]) {
           r[k] = a[i];
           i++;
        } else {
            r[k] = b[j];
            j++;
        }
        k++;
    }
    while (i<na) {
        r[k] = a[i];
        i++;
        k++;
    }
    while (j<nb) {
        r[k] = b[j];
        j++;
        k++;
    }
}

int menosFreq (int v[], int N) {
    int res= v[0];   // O número que vai ganhar
    int min_f= N;    // O recorde de menor frequência (começa no máximo)
    int atual_f= 1;  // Contador para o bloco atual
    int i;
    for(i=1;i<N;i++){
        if(v[i]==v[i-1]) {
            atual_f++;
        } else {
            if(atual_f<min_f) {
                min_f = atual_f;
                res = v[i-1];
            }
            atual_f=1;
        }
    }
    if (atual_f<min_f) {
        res = v[N-1];
    }
    return res;
}

int vizinhos (Posicao p, Posicao pos[], int N) {
    int contagem = 0;
    int i;

    for(i=0;i<N;i++) {
        int dx= p.x - pos[i].x;
        int dy= p.y - pos[i].y;

        if(dx>=-1 && dx<=1 && dy>=-1 && dy<=1) {  // Está colado a mim.
            if(!(dx==0 && dy==0)) {  //Só conta se NÃO for o caso de ambos serem zero.
                contagem++;
            }
        }
    }
    return contagem;
}

int maxCresc (int v[], int N) {
    if (N == 0) return 0; // Se não há números, a sequência é 0

    int max = 1;    // Aquilo que ja contei e armazenei.
    int atual = 1;  // Aquilo que estou a contar no presente.
    int i;

    for (i = 1; i < N; i++) { // Começamos no 1 para comparar com o anterior (i-1)
        if (v[i] >= v[i-1]) {
            atual++;
        } else {
            if (atual > max) {
                max = atual;
            } 
            atual = 1;
        }
    }
    if (atual > max) {
        max = atual;
    }

    return max;
}


// --- MAIN PARA TESTES ---

int main() {
    int questao;
    printf("Escolha a questao para testar (1-10):\n");
    printf("1. remRep  2. insere  3. crescente  4. maisFreq  5. maisCentral\n");
    printf("6. contaVogais  7. contida  8. merge  9. menosFreq  10. vizinhos\n");
    scanf("%d", &questao);
    getchar(); // Limpar o buffer

    switch (questao) {
        case 1: {
            char s[] = "aaabbcddde";
            remRep(s);
            printf("Resultado remRep: %s\n", s);
            break;
        }
        case 2: {
            int v[6] = {10, 20, 30, 40, 50}; // Espaço para mais um
            insere(v, 5, 25);
            printf("Resultado insere: ");
            for(int i=0; i<6; i++) printf("%d ", v[i]);
            printf("\n");
            break;
        }
        case 4: {
            int v[] = {1, 1, 2, 2, 2, 3};
            printf("Mais frequente: %d\n", maisFreq(v, 6));
            break;
        }
        case 5: {
            Posicao p[] = {{10,10}, {1,1}, {5,5}};
            printf("Indice mais central: %d\n", maisCentral(p, 3));
            break;
        }
        case 7: {
            printf("Contida ('abc', 'abcd'): %d\n", contida("abc", "abcd"));
            break;
        }
        case 8: {
            int a[] = {1, 3, 5}, b[] = {2, 4, 6}, r[6];
            merge1(r, a, 3, b, 3);
            printf("Merge: ");
            for(int i=0; i<6; i++) printf("%d ", r[i]);
            printf("\n");
            break;
        }
        case 10: {
            Posicao p = {0,0}, pts[] = {{0,1}, {1,1}, {5,5}};
            printf("Vizinhos de (0,0): %d\n", vizinhos(p, pts, 3));
            break;
        }
        default:
            printf("Questao nao configurada no main ou invalida.\n");
    }

    return 0;
}