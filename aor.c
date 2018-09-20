#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  node * left;
  node * right;
} node;

node * createtree(int value);
void insert(int value, node * tree);


int main(void) {

  int t;
  scanf("%d", &t);
  if (t > 100 && t <= 0) {
    return 0;
  }

  int i;
  for (size_t i = 0; i < t; i++) {
    node * ROOT = NULL;
    int n, j = 0;
    scanf("%d", &n);
    int array[n];

    while (j < n && scanf("%d", array[j]) == TRUE) {   // ainda sem definir parametro
      if (ROOT == NULL) {
        ROOT = createtree(array[j]);
      }else {
        insert(array[j]);
      }
    }
  }

  return 0;
}


node * createtree(int value) {
  node * root;

  root = (node*)malloc(sizeof(node));
  root->data = value;
  root->left = NULL;
  root->right = NULL;

  return tree;
}


void insert(int value, node * tree) {
  if (value <= tree->data) {
    if (tree->left == NULL) {
      node * node = createtree(value);
      tree->left = node;
      return;
    }else {
      insert(value,  tree->left);
    }
  }else {
    if (tree->right == NULL) {
      node * node = createtree(value);
      tree->right = node;
      return;
    }else {
      insert(value, tree->right);
    }
  }
}
