#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

int main () {

}

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int altura (ABin a) {
    int tamanho = 0;

    if(a == NULL) return 0;
    else { 
        tamanho = maximo(altura(a->esq),altura(a->dir)) + 1;
    }
    return tamanho;
}

int maximo (int x, int y) {
    if(x > y) {
        return x;
    } else if(x == y) {
        return x;
    } else {
        return y;
    }
}

int nFolhas (ABin a) {
    if(a==NULL) return 0;
    else if(a->esq==NULL && a->dir==NULL) {
        return 1;
    } else {
        return nFolhas(a->esq) + nFolhas(a->dir);
    }
}

//Forma recursiva.
ABin maisEsquerda (ABin a) {
    ABin r;
    if(a==NULL) r= NULL;

    if(a->esq != NULL) {
        r= maisEsquerda(a->esq);
    } else {
        r= a;
    }
    return r;
}

//Forma iterativa.
ABin maisesquerda1 (ABin a) {
    if(a==NULL) return NULL;

    while(a->esq != NULL) {
        a= a->esq; 
    }
    return a;
}

void imprimeNivel (ABin a, int l) {
    if(a==NULL) return;

    if(l==0) {
        printf("%d", a->valor);
    } else {
        imprimeNivel(a->esq,l-1);
        imprimeNivel(a->dir,l-1);
    }
}

int procuraE (ABin a, int x) {
    if(a==NULL) return 0;

    if(a->valor == x) {
        return 1;
    } else {
        return(procuraE(a->esq,x) || procuraE(a->dir,x));
    }
}

struct nodo *procura (ABin a, int x) {
    // 1. Caso base: não existe
    if (a == NULL) return NULL;

    // 2. Caso base: encontramos o nó! Retornamos o endereço 'a'
    if (a->valor == x) return a;

    // 3. Procurar na esquerda e guardar o resultado
    struct nodo *esq = procura(a->esq, x);
    
    // Se encontrámos na esquerda (ou seja, se não é NULL), devolvemos já!
    if (esq != NULL) return esq;

    // 4. Se não estava na esquerda, tentamos a direita e 
    // retornamos o que quer que venha de lá (o nó ou NULL)
    return procura(a->dir, x);
}

int nivel (ABin a, int x) {
    if(a==NULL) return -1;
    if(a->valor == x) return 0;

    int res;
    if(x<a->valor) {
        res= nivel(a->esq,x);
    } else {
        res= nivel(a->dir,x);
    }
    if (res == -1) return -1;

    return 1+res;
}

void imprimeAte (ABin a, int x) {
    if(a==NULL) return;

    if(a->valor<x) {
        imprimeAte(a->esq,x);
        printf("%d",a->valor);
        imprimeAte(a->dir,x);
    } else {
        imprimeAte(a->esq,x);
    }
}