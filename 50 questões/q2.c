#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

int main () {

}

// QUESTÃO 1
int length (LInt l) {
    int conta= 0;

    while(l != NULL) {
        conta++;
        l = l->prox; // agora o meu l passa a ser o resto da lista.
    }
    return conta;
}

// QUESTÃO 2
void freeL (LInt l) {
    LInt aux;

    while(l != NULL) {
        aux = l->prox; //para apagarmos o primeiro, temos de guardar o proximo numa variável auxiliar, para de seguida o eliminar.
        free(l);
        l= aux;
    }
}

// QUESTÃO 3
void imprimeL (LInt l) {
    while(l != NULL) {
        printf("O valor é: %d\n",l->valor);
        l= l->prox;
    }
}

// QUESTÃO 4
LInt reverseL (LInt l) {
    LInt ant = NULL;
    LInt prox_no = NULL;

    while(l!=NULL) {
        prox_no = l->prox;
        l->prox = ant;
        ant = l;
        l = prox_no;
    }
    return ant;
}

// QUESTÃO 5
void insertOrd (LInt *l, int x) {
    LInt novo = malloc(sizeof(struct lligada));
    if(novo==NULL) return;

    novo->valor = x;
    novo->prox = NULL;

    if (*l== NULL || x< (*l)->valor) {
        novo->prox = (*l);
        (*l) = novo;
    } else {
        LInt atual = (*l);

        while(atual->prox !=NULL && atual->prox->valor < x) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

// QUESTÃO 6
int removeOneOrd (LInt *l, int x) {
    if(*l==NULL) return 1;

    LInt temp;

    if((*l)->valor==x) {
        temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
        return 0;
    }

    LInt atual = (*l);
    while(atual->prox!=NULL && atual->prox->valor < x) {
        atual = atual->prox;
    }

    if(atual->prox != NULL && atual->prox->valor==x) {
        temp = atual->prox;
        atual->prox = temp->prox;
        free(temp);
        return 0;
    }
    return 1;
}

// QUESTÃO 7 
void merge (LInt *r, LInt a, LInt b) {
    if(a == NULL) { *r= b; return; }
    if(b==NULL) { *r= a; return; }

    if(a->valor < b->valor) {
       *r = a;
        a = a->prox;
    } else {
        *r = b;
        b = b->prox;
    }
    LInt ultimo = *r;

    while(a!=NULL && b!=NULL) {
        if(a->valor < b->valor) {
            ultimo->prox = a;
            a = a->prox;
        } else {
            ultimo->prox = b;
            b = b->prox;
        }
        ultimo = ultimo->prox;
    }
    if(a != NULL) {
        ultimo->prox = a;
    } else {
        ultimo->prox = b;
    }
} 

// QUESTÃO 8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    // Inicializamos as listas como vazias
    *mx = NULL;
    *Mx = NULL;

    while (l != NULL) {
        LInt proximo_no = l->prox; // 1. Guardamos o resto da lista original

        if (l->valor < x) {
            *mx = l;           // 2. O nó atual entra na lista dos menores
            mx = &(l->prox);   // 3. O ponteiro 'mx' aponta agora para o 'prox' deste nó
        } else {
            *Mx = l;           // 2. O nó atual entra na lista dos maiores
            Mx = &(l->prox);   // 3. O ponteiro 'Mx' aponta agora para o 'prox' deste nó
        }

        l = proximo_no;        // 4. Saltamos para o que guardámos no início
    }

    // 5. O toque final: garantir que as duas listas terminam em NULL
    *mx = NULL;
    *Mx = NULL;
}

// QUESTÃO 10
int removeAll (LInt *l, int x) {
    if(*l==NULL) return 0;

    int count = 0;
    while(*l!=NULL && (*l)->valor == x) {
        LInt temp = *l;
        (*l) = (*l)->prox;
        free(temp);
        count ++;
    }
    LInt atual = *l;
    while(atual!=NULL && atual->prox != NULL) {
        if(atual->prox->valor==x) {
            LInt temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
            count ++;
        } else {
            atual = atual->prox;
        }
    }
    return count;
}