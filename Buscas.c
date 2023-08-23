// TRabalhos dos estudantes do 3 ano Engenharia Informatica: Djavs Ricardo Tivane & Osvaldo Anastácio Chicue


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para imprimir os nós por busca em profundidade (DFS)
void imprimirDFS(struct No* no) {
    if (no == NULL)
        return;
    printf("%d ", no->dado);
    imprimirDFS(no->esquerda);
    imprimirDFS(no->direita);
}

// Função para imprimir os nós por busca em largura (BFS)
void imprimirBFS(struct No* raiz) {
    if (raiz == NULL)
        return;

    struct No* fila[20]; // Supondo que a árvore tem no máximo 20 nós
    int inicio = 0, fim = 0;

    fila[fim++] = raiz;

    while (inicio < fim) {
        struct No* atual = fila[inicio++];
        printf("%d ", atual->dado);

        if (atual->esquerda != NULL)
            fila[fim++] = atual->esquerda;
        if (atual->direita != NULL)
            fila[fim++] = atual->direita;
    }
}

int main() {
    // Construindo a árvore com 20 nós
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

    printf("Nós por busca em profundidade: ");
    imprimirDFS(raiz);
    printf("\n");

    printf("Nós por busca em largura: ");
    imprimirBFS(raiz);
    printf("\n");

    return 0;
}

