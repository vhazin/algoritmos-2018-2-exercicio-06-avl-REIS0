#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  int data;
  struct node * left;
  struct node * right;
  struct node * father;
  int height;
} node;


node * createtree(int value); // cria arvore
node * insert(int value, node * root); // inserir na arvore
int height(node * root); // checar altura dos nós
int attheight(node * root); // atualizar altura da arvore
int check(node * root); // checar se arvore é avl


int main(void) {

  int t;
  scanf("%d", &t); // case test
  if (t > 100 || t <= 0) { // case test condition
    return 0;
  }
  int arr[t];

  int i = 0;
  while (i < t) {
    node * ROOT = NULL;
    size_t n, j = 0;
    scanf("%d", &n);
    int array[n];

    while (j < n) {
      scanf("%d", &array[j]);
      if (ROOT == NULL) {
        ROOT = createtree(array[j]);
      }else {
        insert(array[j], ROOT);
      }
      j++;
    }

    arr[i] = check(ROOT);
    i++;
  }

  i = 0;
  while (i < t) {
    if (arr[i] == 1) {
      printf("T");
    }else {
      printf("F");
    }
    i++;
    printf("\n");
  }

  return 0;
}


node * createtree(int value) {
  node * root;

  root = (node*)malloc(sizeof(node));
  root->data = value;
  root->left = NULL;
  root->right = NULL;
  root->father = NULL;
  root->height = 0;

  return root;
}


node * insert(int value, node * root) {
  if (value == -1) {
    return NULL;
  }
  if (root == NULL) {
    root = createtree(value);
  }
  else if (value < root->data) {
    root->left = insert(value, root->left);
    root->left->father = root;
  }else {
    root->right = insert(value, root->right);
    root->right->father = root;
  }

  attheight(root);
  return root;
}


int height(node * root) {
  if (root == NULL) {
    return 0;
  }else {
    return root->height;
  }
}


int attheight(node * root) {
  int esqh;
  int dirh;

  if (root != NULL) {
    esqh = height(root->left);
    dirh = height(root->right);

    if (dirh > esqh) {
      root->height = dirh + 1;
    }else {
      root->height = esqh + 1;
    }
  }
  return 0;
}


int check(node * root) {
  if (root == NULL) {
    return 1;
  }

  int esq = height(root->left);
  int dir = height(root->right);
  int result = dir - esq;
  printf("%d\n", result);

  if (result > 1 || result < -1) {
    return 0;
  }

  return 1;
}
