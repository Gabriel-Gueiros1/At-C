#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int val;
 struct Node* left;
 struct Node* right;
} Node;

Node* createNode(int val) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 if(newNode == NULL) {
   printf("Erro ao criar um novo nó.\n");
   exit(0);
 }
 newNode->val = val;
 newNode->left = NULL;
 newNode->right = NULL;

 return newNode;
}

Node* insert(Node* root, int val) {
 
 if(root == NULL) {
   root = createNode(val);
 }
 
 else {
   
   if(val < root->val) {
       root->left = insert(root->left, val);
   }
   
   else {
       root->right = insert(root->right, val);
   }
 }

 return root;
}

void imprimirNiveis(Node* raiz) {
 if(raiz == NULL) {
   return;
 }

 Node* fila[100];
 int inicio = 0;
 int fim = 0;
 fila[fim++] = raiz;

 while(inicio < fim) {
  int tamanho = fim - inicio;
  for(int i = 0; i < tamanho; i++) {
      Node* atual = fila[inicio++];

      printf("%d ", atual->val);

      if(atual->left != NULL) {
          fila[fim++] = atual->left;
      }
      if(atual->right != NULL) {
          fila[fim++] = atual->right;
      }
  }
  printf("\n");
 }
}

int main() {
 Node* root = NULL;
 int data[] = {200, 450, 123, 52, 133, 321, 422, 523, 36, 64};
 int size = sizeof(data) / sizeof(data[0]);

 for(int i = 0; i < size; i++) {
   root = insert(root, data[i]);
 }

 printf("Arvore em niveis ordenados:\n");
 imprimirNiveis(root);
 printf("\n");

 return 0;
}