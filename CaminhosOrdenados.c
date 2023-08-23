#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura de um n� da �rvore
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

// Defini��o da estrutura da pilha
struct NoPilha {
    struct No* valor;
    struct NoPilha* proximo;
};

// Fun��o para criar um novo n� da �rvore
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Fun��o para criar um novo n� da pilha
struct NoPilha* criarNoPilha(struct No* valor) {
    struct NoPilha* novoNoPilha = (struct NoPilha*)malloc(sizeof(struct NoPilha));
    novoNoPilha->valor = valor;
    novoNoPilha->proximo = NULL;
    return novoNoPilha;
}

// Fun��o para empilhar um n� na pilha
void empilhar(struct NoPilha** topo, struct No* valor) {
    struct NoPilha* novoNoPilha = criarNoPilha(valor);
    novoNoPilha->proximo = *topo;
    *topo = novoNoPilha;
}

// Fun��o para desempilhar um n� da pilha
struct No* desempilhar(struct NoPilha** topo) {
    if (*topo == NULL)
        return NULL;

    struct NoPilha* temp = *topo;
    struct No* valor = temp->valor;
    *topo = (*topo)->proximo;
    free(temp);
    return valor;
}

// Fun��o para imprimir os elementos da pilha (caminho) de forma ordenada
void imprimirPilhaOrdenada(struct NoPilha* topo) {
    if (topo == NULL)
        return;

    imprimirPilhaOrdenada(topo->proximo);
    printf("%d ", topo->valor->valor);
}

// Fun��o para percorrer e imprimir os caminhos de forma ordenada
void imprimirCaminhosOrdenados(struct No* raiz, struct NoPilha* pilha) {
    if (raiz == NULL)
        return;

    empilhar(&pilha, raiz);

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        imprimirPilhaOrdenada(pilha);
        printf("\n");
    }

    imprimirCaminhosOrdenados(raiz->esquerda, pilha);
    imprimirCaminhosOrdenados(raiz->direita, pilha);

    desempilhar(&pilha);
}

int main() {
    // Construindo a �rvore com 20 n�s
    struct No* raiz = criarNo(1);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    raiz->esquerda->esquerda = criarNo(4);
    raiz->esquerda->direita = criarNo(5);
    raiz->direita->esquerda = criarNo(6);
    raiz->direita->direita = criarNo(7);
    raiz->esquerda->esquerda->esquerda = criarNo(8);
    raiz->esquerda->esquerda->direita = criarNo(9);
    raiz->esquerda->direita->esquerda = criarNo(10);
    raiz->esquerda->direita->direita = criarNo(11);
    raiz->direita->esquerda->esquerda = criarNo(12);
    raiz->direita->esquerda->direita = criarNo(13);
    raiz->direita->direita->esquerda = criarNo(14);
    raiz->direita->direita->direita = criarNo(15);
    raiz->esquerda->esquerda->esquerda->esquerda = criarNo(16);
    raiz->esquerda->esquerda->esquerda->direita = criarNo(17);
    raiz->esquerda->esquerda->direita->esquerda = criarNo(18);
    raiz->esquerda->esquerda->direita->direita = criarNo(19);
    raiz->esquerda->direita->esquerda->esquerda = criarNo(20);

    struct NoPilha* pilha = NULL;

    printf("Caminhos de todos os n�s (impress�o ordenada):\n");
    imprimirCaminhosOrdenados(raiz, pilha);

    return 0;
}

