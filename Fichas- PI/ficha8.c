#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue; 

int main () {

}


void initStack (Stack *s) {
    *s = NULL;
}

int SisEmpty (Stack s) {
    if(s == NULL) {
        return 1;
    }
    return 0;
}

int push (Stack *s, int x) {
    LInt novo_no = newLInt(x,*s);
    if (novo_no == NULL){
        return 1;
    }
    *s= novo_no;
    return 0;
}

int pop (Stack *s, int *x) {
    if(*s==NULL) {
        return 1;
    }
    *x= (*s)->valor;
    LInt aux = *s;
    aux = *s;
    *s = (*s)->prox;
    free(aux);
    return 0;
}

int top (Stack s, int *x) {
    if(s==NULL) {
        return 1;
    }
    *x = s->valor;
    return 0;
}

void initQueue (Queue *q) {
    q-> inicio = NULL;
    q-> fim = NULL;
}

int QisEmpty (Queue q) {
    if(q.inicio == NULL) {
        return 1;
    }
    return 0;
}

int enqueue (Queue *q, int x) {
    LInt novo = newLInt(x,NULL);
    if (novo == NULL) {
        return 1;
    }
    if (q->inicio == NULL) {
        q->inicio = novo; // Se a fila estava vazia, o novo nó é o primeiro.
    } else {
        q->fim->prox = novo; // Se não estava vazia, "engatamos" no que era o último.
        return 0;
    }
}

int dequeue (Queue *q, int *x) {
    if (q->inicio == NULL) {
        return 1;
    }
    *x= q->inicio->valor;
    LInt aux = *x;
    q->inicio = q->inicio->prox; // o inicio da fila passa a ser o 2elemento;
    if(q->inicio == NULL) {
        q->fim = NULL;
    }
    free(aux);
    return 0;
}

typedef LInt QueueC;

void initQueueC (QueueC *q) {
    *q = NULL;
}

int QisEmptyC (QueueC q) {
    if(q==NULL) {
        return 1;
    }
    return 0;
}

int enqueueC (QueueC *q, int x) { //inserção de um novo elemento.
    LInt novo = newLInt(x,NULL);
    if(novo==NULL) return 1;

    if(!QuisEmpty(*q)) {
    novo->prox = (*q)->prox; //1 elemento (*q) é o ultimo elemento 
    (*q)->prox = novo;

    *q= novo;
    } else {
        novo->prox = novo;
    }
    *q= novo;
    returm 0;
}

int dequeueC (QueueC *q, int *x) { //retirar o primeiro elemento.
    if(QuisEmpty(*q)) return 1;

    *x = (*q)->prox->valor;

    if ((*q)->prox == *q) {
        free(*q);
        *q = NULL;
    } else {
        LInt aux = (*q)->prox->prox; //crio um apontador po 2 elemento
        free((*q)->prox); //elimino o 1 elemento.
        (*q)->prox = aux; // o 1 elemento passa a ser o 2.
    }
    return 0;

}

typedef struct dlist { //cada célula vai apontar para o primeiro elemento e para o anterior.
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

void initDeque (Deque *q) { //Como se trata de * tenho de fzr ->
    q->front = NULL;
    q->back = NULL;
}

int DisEmpty (Deque q) {
    return q.front==NULL;
}

int pushBack (Deque *q, int x) {
    DList novo = newDList (x,NULL);
    if(novo==NULL) return 1;

    novo->ant = q->back;

    if(DisEmpty(*q)) {
        q->back = q->front = novo; // so tenho 1 elemento, o back e o front para esse mesmo elemento
    } else {
        q->back->prox = novo;
        q->back = novo;
    }
}
