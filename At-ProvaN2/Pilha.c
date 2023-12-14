#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 10

int dados[TAMANHO_PILHA];
int topo = -1;

void inicializarPilha() {
    topo = -1;
}

int pilhaEstaVazia() {
    return topo == -1;
}

int pilhaEstaCheia() {
    return topo == TAMANHO_PILHA - 1;
}

void empilhar(int valor) {
    if (pilhaEstaCheia()) {
        printf("A Pilha está cheia!!!!\n");
        return;
    }

    if (topo == -1) {
        topo = 0;
        dados[topo] = valor;
    } else {
        dados[++topo] = valor;
    }

    printf("Elemento %d empilhado\n", valor);
}

int desempilhar() {
    if (pilhaEstaVazia()) {
        printf("Erro: A Pilha está vazia\n");
        return -1;
    }

    int valorDesempilhado = dados[topo--];
    printf("Elemento %d desempilhado\n", valorDesempilhado);
    return valorDesempilhado;
}

int main() {
    inicializarPilha();

    int elementos[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(elementos) / sizeof(elementos[0]); i++) {
        empilhar(elementos[i]);
    }

    printf("Desempilhando elementos:\n");
    while (!pilhaEstaVazia()) {
        int valorDesempilhado = desempilhar();
    }

    return 0;
}