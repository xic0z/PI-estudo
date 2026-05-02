#include <stdio.h>

#define Max 100

// 1. Primeiro defines a estrutura e os nomes (STACK e SStack)
typedef struct staticStack {
    int sp;
    int values[Max];
} STACK, *SStack;

void SinitStack (SStack s) {
    s->sp = 0;
}

int main() {
    struct staticStack minhaStack; // Criar a stack
    
    SinitStack(&minhaStack); // Inicializar passando o endereço (&)
    
    printf("Stack inicializada. SP = %d\n", minhaStack.sp);
    
    return 0;
}

int SisEmpty (SStack s) {
    if (s->sp == 0) {
        return 1;
    }
    return 0;
}

int Spush (SStack s, int x) {
    if(s->sp == Max) {
        return -1; 
    }
    else { 
        s->values[s->sp] =x;
        s->sp++;
        return 0;
    }
}

int Spop (SStack s, int *x) {
    if(s->sp == 0) {
        return 1;
    }
    else {
        s->sp--;
        *x = s->values[s->sp];
        return 0;
    }
}

int Stop (SStack s, int *x) {
    if(s->sp == 0) {
        return 1;
    }
    else {
        *x = s->values[s->sp - 1];
        return 0;
    }
}

struct staticQueue {
    int front; // Indica a posição do primeiro elemento da fila.
    int length; // Indica quantos elementos estão na fila atualmente.
    int values [Max];
} QUEUE, *SQueue;

void SinitQueue (SQueue q) {
    q -> front = 0;
    q -> length = 0;
}

int SisEmptyQ (SQueue q) {
    if(q->length== 0) {
        return 1;
    }
    return 0;
}

int Senqueue (SQueue q, int x) {
    if(q->length == Max) {
        return 1;
    }
    else {
        int pos = (q->front + q->length) % Max; //calculo da pos final.
        q->values[pos]=x;
        q->length++;
        return 0;
    }
}

int Sdequeue (SQueue q, int *x) {
    if(q->length==0) {
        return 1;
    }
    else {
        *x = q->values[q->front]; // colocar no endereco x o valor de quem esta na posicao inicial (front).
        q->front = (q->front +1) % Max;
        q->length--;
        return 0;
    }
}

int Sfront (SQueue q, int *x) {
    if(q->length==0) {
        return 1;
    }
    else {
        *x = q->values[q->front];
        return 0;
    }
}

