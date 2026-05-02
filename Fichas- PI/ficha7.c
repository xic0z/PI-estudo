#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura das palavras
typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

// --- A tua função que limpa tudo ---
void libertaLista (Palavras l) {
    Palavras temp;
    while (l != NULL) {
        temp = l->prox;
        free(l->palavra); // Limpa o texto
        free(l);          // Limpa o vagão
        l = temp;
    }
}

int main() {
    // 1. Criar manualmente uma pequena lista para teste
    // Nó 1
    Palavras lista = malloc(sizeof(struct celula));
    lista->palavra = strdup("Ola"); // strdup aloca memória para a string
    lista->ocorr = 1;

    // Nó 2
    lista->prox = malloc(sizeof(struct celula));
    lista->prox->palavra = strdup("Mundo");
    lista->prox->ocorr = 2;
    lista->prox->prox = NULL; // Fim da lista

    printf("Lista criada na memória.\n");

    // 2. Chamar a tua função de limpeza
    libertaLista(lista);
    
    printf("Memória libertada com sucesso!\n");

    return 0;
}

int quantasP (Palavras l) {
    int contador = 0;

    while(l!=NULL) {
        contador++;
        l= l->prox;
    }
    return contador;
}

void listaPal (Palavras l) {
    while(l!=NULL) {
        printf("%s %d\n", l->palavra, l->ocorr);
        l=l->prox;
    }
}

char * ultima (Palavras l) {
    if(l==NULL) {
        return NULL;
    }
    while(l->prox!=NULL) {
        l=l->prox;
    }
    return l->palavra;
}
// Imagina uma lista com 3 palavras: "Cão" -> "Gato" -> "Rato" -> NULL.
// Início: O teu dedo l aponta para "Cão".
// Teste do While: Tu olhas para o braço do "Cão". Ele aponta para o "Gato"? Sim (l->prox != NULL).
// Ação: O teu dedo l salta para o "Gato".
// Teste do While: Tu olhas para o braço do "Gato". Ele aponta para o "Rato"? Sim (l->prox != NULL).
// Ação: O teu dedo l salta para o "Rato".
// Teste do While: Tu olhas para o braço do "Rato". Ele aponta para alguém? Não, aponta para o vazio (l->prox == NULL).
// Ação: O ciclo pára. O teu dedo l ficou parado no "Rato".

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = strdup(p);
    novo->ocorr = 1;
    novo->prox = l;
    return novo;
}

// Tu tens um comboio já montado: Joana -> Paulo -> Maria -> NULL.
// A Joana é o teu l (o início).
// Agora, queres acrescentar o Ricardo (a nova palavra p) no início.
// Os 4 Passos da Lógica:
// Criar o Ricardo (malloc):
// O Ricardo não existe no comboio. Primeiro tens de o "chamar" para o jogo. O malloc reserva um lugar no mundo para ele existir.
// Dar as coisas ao Ricardo:
// Tu dás-lhe o papel com a palavra (ex: "Ricardo") e dizes-lhe: "Tu apareces 1 vez".
// A Ligação Crítica (novo->prox = l):
// Aqui é que a magia acontece. Tu dizes ao Ricardo: "Agarra a cintura da Joana".
// Repara: O Ricardo agora está a apontar para a Joana.
// A Joana ainda está a apontar para o Paulo.
// O comboio agora é: Ricardo -> Joana -> Paulo -> Maria -> NULL.
// A Nova Cabeça (return novo):
// Quem te perguntou "Onde começa o comboio?" antes recebia a Joana. Mas agora o comboio começa no Ricardo. Por isso, tu devolves o Ricardo como sendo o novo início.

Palavras acrescentaFim (Palavras l, char *p) {
    // 1. Criar o novo vagão e preencher os dados
    Palavras novo = malloc(sizeof(struct celula));
    novo->palavra = strdup(p);
    novo->ocorr = 1;
    novo->prox = NULL; // Ele vai ser o último, por isso aponta para o vazio

    // 2. CASO ESPECIAL: Se a lista estiver vazia
    if (l == NULL) {
        return novo; // O novo nó passa a ser o início da lista
    }

    // 3. CASO GERAL: O comboio já tem vagões
    // Usamos um 'aux' para não perder o início da lista (l)
    Palavras aux = l; 
    
    // Viajamos até encontrar o nó cujo próximo é NULL (o último)
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    // 4. O ENGATE: O antigo último agora aponta para o nosso novo nó
    aux->prox = novo;

    // 5. Retornamos o início da lista original
    return l;
}