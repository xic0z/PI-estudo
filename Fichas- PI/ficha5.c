#include <stdio.h> 
#include <string.h>

typedef struct aluno {
int numero;
char nome[100];
int miniT [5];
float teste;
} Aluno;

int nota (Aluno a) {
    int somaMiniT = 0;
    for(int i=0;i<5;i++){
        somaMiniT += a.miniT[i];
    }
    float mediaFinal = (a.teste + somaMiniT) / 2.0;
    if (mediaFinal < 9.5) {
        return 0;
    }
    return (int)(mediaFinal + 0.5);
}

// int main() {
//     Aluno aluno1;
    
//     // Preenchendo os mini-testes com notas de 0 a 4
//     aluno1.miniT[0] = 3;
//     aluno1.miniT[1] = 4;
//     aluno1.miniT[2] = 2;
//     aluno1.miniT[3] = 3;
//     aluno1.miniT[4] = 3; // Soma = 15
    
//     aluno1.teste = 12.0; // Nota do teste
    
//     // Cálculo esperado: (15 + 12) / 2 = 13.5 -> Arredonda para 14
//     int resultado = nota(aluno1);
    
//     printf("Nota Final: %d\n", resultado);
    
//     return 0;
// }

int procuraNum (int num, Aluno t[], int N) {
    int i;
    for(i=0;i<N;i++) {
        if(num==t[i].numero) return i;
    }
    return -1;
}

int main() {
    // 1. Criar um array de Alunos (ex: capacidade para 10, mas vamos usar 3)
    Aluno turma[10];
    int totalAlunos = 3;

    // 2. Preencher alguns dados (IMPORTANTE: Números em ordem crescente)
    turma[0].numero = 1001;
    strcpy(turma[0].nome, "Ana");
    
    turma[1].numero = 2500;
    strcpy(turma[1].nome, "Bruno");
    
    turma[2].numero = 3200;
    strcpy(turma[2].nome, "Carla");

    // 3. Definir o número que queremos procurar
    int numeroProcurado = 2500;

    // 4. Chamar a função
    int indice = procuraNum(numeroProcurado, turma, totalAlunos);

    // 5. Mostrar o resultado
    printf("--- Teste de Procura ---\n");
    if (indice != -1) {
        printf("Aluno encontrado na posicao: %d\n", indice);
        printf("Nome do aluno: %s\n", turma[indice].nome);
    } else {
        printf("Erro: Aluno com numero %d nao encontrado.\n", numeroProcurado);
    }

    // Teste com um número que NÃO existe
    printf("\nProcurando numero inexistente (9999)...\n");
    if (procuraNum(9999, turma, totalAlunos) == -1) {
        printf("Resultado: -1 (Correto!)\n");
    }

    return 0;
}

void ordenaPorNum(Aluno t[], int N) {
    int i,j;
    Aluno temp;

    for(i=0;i<N-1;i++){
        for(j=0;j<N-1-i;j++) {
            if(t[j.numero] > t[j+1].numero) {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }
}
