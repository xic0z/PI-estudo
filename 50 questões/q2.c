#include <stdio.h>
#include <stdlib.h>

/*
 * =============================================================
 *               LISTAS LIGADAS — PROGRAMAÇÃO IMPERATIVA
 * =============================================================
 */

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

// QUESTÃO 11
int removeDups (LInt *l) {
    if(*l==NULL) return 0;

    int count = 0;
    LInt fixo = *l;

    while(fixo!=NULL) {
        LInt anterior = fixo;

        while(anterior->prox!=NULL){
            if(anterior->prox->valor == fixo->valor) {
                LInt temp = anterior->prox;
                anterior->prox = temp->prox;
                free(temp);
                count++;
            } else {
                anterior = anterior->prox;
            }
        }
        fixo = fixo->prox;
    }
    return count;
}

// QUESTÃO 12
int removeMaiorL (LInt *l) {
    LInt anterior = (*l);
    LInt atual = (*l)->prox;

    LInt antMaior = NULL;
    int maxValor = (*l)->valor;

    while(atual!=NULL) {
        if(atual->valor > maxValor) {
            maxValor = atual->valor;
            antMaior = anterior;
        }
        anterior = atual;
        atual = atual->prox;
    }
    LInt aRemover;
    if(antMaior == NULL) {
        aRemover = (*l);
        *l = (*l)->prox;
    } else {
        aRemover = antMaior->prox;
        antMaior->prox = aRemover->prox;
    }
    free(aRemover);
    return maxValor;
}

// QUESTÃO 13 
void init (LInt *l) {
    LInt atual = (*l);
    if(atual->prox==NULL) {
        free(atual);
        *l = NULL;
        return;
    }
    while(atual->prox->prox != NULL) {
        atual = atual->prox; //Da info do penultimo elemento
    }
    LInt ultimo = atual->prox;
    atual->prox = NULL;
    free(ultimo);
}

// QUESTÃO 14
void appendL (LInt *l, int x) {
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = x;
    novo->prox = NULL;

    if(*l==NULL) {
        *l = novo;
        return;
    }
    LInt atual = (*l);
    while(atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

// QUESTÃO 15
void concatL (LInt *a, LInt b) {
    if(*a==NULL) {
        *a = b;
        return;
    }
    LInt atual = (*a);
    while(atual->prox != NULL) {
        atual = atual->prox; //chegar ao fim da lista a
    }
    atual->prox = b;
}

// QUESTÃO 16
LInt cloneL (LInt l) {
    if(l==NULL) return NULL;

    LInt novaLista = malloc(sizeof(struct lligada));
    novaLista->valor = l->valor;

    LInt ultimo = novaLista;

    LInt atual = l->prox;
    while(atual!= NULL) {
        LInt novoNo = malloc(sizeof(struct lligada));
        novoNo->valor = atual->valor;
        ultimo->prox = novoNo;
        atual = atual->prox;
    }
    ultimo->prox = NULL;
    return novaLista;
}   

// QUESTÃO 17
LInt cloneRev (LInt l) {
    if(l==NULL) return NULL;

    LInt novaLista = NULL;
    LInt atual = l;

    while(atual!=NULL) {
        LInt novoNo = malloc(sizeof(struct lligada));
        novoNo->valor = atual->valor;
        novoNo->prox = novaLista;
        novaLista = novoNo;
        atual = atual->prox;
    }
    return novaLista;
}

// QUESTÃO 19
int take (int n, LInt *l) {
    if(*l==NULL) return 0;
    if(n<=0) {
        LInt atual = *l;
        int conta = 0;
        while(atual!=NULL) {
            LInt temp = atual;
            atual = atual->prox;
            free(temp);
            conta++;
        }
        *l = NULL;
        return 0;
    }
    LInt atual = *l;
    int i = 1;

    while(i<n && atual->prox != NULL) {
        atual = atual->prox;
        i++;
    }
    if (atual->prox == NULL) return i;

    LInt prox = atual->prox;
    atual->prox = NULL;

    while(prox!=NULL) {
        LInt temp = prox;
        prox = prox->prox;
        free(temp);
    }
    return n;
}

// QUESTÃO 20
int contaElem (LInt l) {
    int contador = 0;
    
    while (l != NULL) {
        contador++;   
        l = l->prox;  
    }
    
    return contador;
}

int drop (int n, LInt *l) {
    if(*l==NULL) return 0;
    if(n<=0) return contaElem(*l);

    LInt atual = *l;
    int apagados = 0;

    while(apagados<n && *l!=NULL) {
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
        apagados++;
    }
    return contaElem(*l);
}

// QUESTÃO 22
int listToArray (LInt l, int v[], int N) {
    if(l==NULL) return 0;

    int i = 0;
    while(l!=NULL && i<N) {
        v[i] = l->valor;
        l = l->prox;
        i++;
    }
    return i;
}

// QUESTÃO 23
LInt arrayToList (int v[], int N) {
    if(N==0) return NULL;
    
    LInt inicio = malloc(sizeof(struct lligada));
    inicio->valor = v[0];
    inicio->prox = NULL;

    LInt atual = inicio;

    for(int i=1;i<N;i++) {
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = v[i];
        novo->prox = NULL;

        atual->prox = novo;

        atual = novo;
    }
    return inicio;
}

// QUESTÃO 24
LInt somasAcL (LInt l) {
    if(l==NULL) return 0;

    LInt novaLista = malloc(sizeof(struct lligada));
    int soma = l->valor;
    novaLista->valor = soma;
    novaLista->prox = NULL;

    LInt ultimo = novaLista;
    LInt atual = l->prox;

    while(atual!=NULL) {
        soma += atual->valor;

        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = soma;
        novo->prox = NULL;

        ultimo->prox = novo;
        ultimo = novo;

        atual = atual->prox;
    }
    return novaLista;
}

// QUESTÃO 27

/*
 * =============================================================
 *              ÁRVORES BINÁRIAS — PROGRAMAÇÃO IMPERATIVA
 * =============================================================
 */

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// QUESTÃO 28
int altura (ABin a) {
    if (a==NULL) {
        return 0;
    } 

    int alt_esq = altura(a->esq);
    int alt_dir = altura(a->dir);

    if(alt_esq > alt_dir) {
        return 1 + alt_esq;
    } else {
        return 1 + alt_dir;
    }
}

// QUESTÃO 29
ABin cloneAB (ABin a) {
    if (a==NULL) return NULL;

    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = a->valor;

    novo->esq = cloneAB(a->esq);
    novo->dir = cloneAB(a->dir);

    return novo;
}

// QUESTÃO 30
void mirror (ABin *a) {
    if(*a==NULL) return;
    
    ABin temp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = temp;

    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
}

// QUESTÃO 31
void inorder (ABin a , LInt *l) {
    if(a==NULL) return;

    inorder(a->dir,l);
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = a->valor;
    novo->prox = (*l);
    (*l) = novo;
    inorder(a->esq,l);
}

// QUESTÃO 34 
int depth (ABin a, int x) {
    if(a==NULL) return -1;
    if(a->valor==x) return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1) return 1 + dir;
    if(dir == -1) return 1 + esq;

    return 1 + (esq<dir ? esq : dir);
}

// QUESTÃO 35
int freeAB (ABin a) {
    if(a==NULL) return 0;

    int esq = freeAB(a->esq);
    int dir = freeAB(a->dir);

    free(a);

    return 1 + esq + dir;
}

// QUESTÃO 36
int pruneAB (ABin *a, int l) {
    if(*a==NULL) return 0;

    int contagem = 0;

    if(l>0) {
        int esq = pruneAB(&((*a)->esq),l-1);
        int dir = pruneAB(&((*a)->dir),l-1);
        return contagem += esq+dir;
    } else if(l==0) {
        contagem += freeAB((*a)->esq);
        contagem += freeAB((*a)->dir);
        (*a)->esq = NULL;
        (*a)->dir = NULL;
    }
    return contagem;
}

// QUESTÃO 37
int iguaisAB (ABin a, ABin b) {
    if(a==NULL && b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    if(a->valor!=b->valor) return 0;

    return(iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
}

// QUESTÃO 42
int contaFolhas (ABin a) {
    if(a==NULL) return 0;
    if(a->esq==NULL && a->dir==NULL) return 1;

    int total_esq = contaFolhas(a->esq);
    int total_dir = contaFolhas(a->dir);
    return total_esq + total_dir;
}

// QUESTÃO 44
int addOrd (ABin *a, int x) {
    if(a==NULL) return 0;
    if((*a)->valor == x) return 1;

    ABin atual = (*a);
    ABin anterior = NULL;
    while(atual!=NULL) {
        if(x==atual->valor) {
            return 1;
        } else if(x<atual->valor) {
            anterior = atual;
            atual = atual->esq;
        } else {
            anterior=atual;
            atual = atual->dir;
        }
    }
    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;

    if(anterior == NULL) {
        (*a)=novo;
    } else if(x<anterior->valor) {
        anterior->esq = novo;
    } else {
        anterior->dir = novo;
    }
    return 0;
}

// QUESTÃO 45
int lookupAB (ABin a, int x)  {
    if(a==NULL) return 0;

    ABin atual = a;

    while(atual!=NULL) {
        if(x == atual->valor) {
            return 1;
        } else if (x < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    return 0;
}

// QUESTÃO 47
int maiorAB (ABin a) {
    if (a==NULL) return -1;

    ABin atual = a;

    while(atual->dir!=NULL) {
        atual = atual->dir;
    }
    return atual->valor;
}

// QUESTÃO 49
int quantosMaiores (ABin a, int x) {
    if(a==NULL) return 0;

    if(a->valor > x) {
        return 1 + quantosMaiores (a->dir,x) + quantosMaiores(a->esq,x);
    } else {
        return quantosMaiores(a->dir,x);
    }
}