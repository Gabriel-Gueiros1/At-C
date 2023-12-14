#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA 10

typedef struct {
    int items[TAMANHO_FILA];
    int front, rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue *queue) {
    return (queue->rear == TAMANHO_FILA - 1);
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Erro: fila está cheia. %d\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->items[queue->rear] = value;
    printf("Enfileirado: %d\n", value);
}

int dequeue(Queue *queue) {
    int item;

    if (isEmpty(queue)) {
        printf("Erro: fila está vazia.\n");
        return -1;
    }

    item = queue->items[queue->front];

    if (queue->front == queue->rear) {

        initializeQueue(queue);
    } else {
        queue->front++;
    }

    printf("Desenfileirado: %d\n", item);
    return item;
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Fila vazia\n");
        return;
    }

    printf("Fila: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 64);
    enqueue(&myQueue, 25);
    enqueue(&myQueue, 12);
    enqueue(&myQueue, 22);
    enqueue(&myQueue, 11);
    enqueue(&myQueue, 9);

    printQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);

    printQueue(&myQueue);

    return 0;
}