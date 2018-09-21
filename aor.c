#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  int data;
  struct node * left;
  struct node * right;
} node;


node * createtree(int value);
void insert(int value, node * tree);
int height(node * root);
int check(node * root);


int main(void) {

  int t;
  scanf("%d", &t);
  if (t > 100 && t <= 0) {
    return 0;
  }
  char arr[t];

  int i;
  for (size_t i = 0; i < t; i++) {
    node * ROOT = NULL;
    int n, j = 0;
    scanf("%d", &n);
    int array[n];

    while (j < n && scanf("%d", array[j]) == 1) {   // ainda sem definir parametro
      if (ROOT == NULL) {
        ROOT = createtree(array[j]);
      }else {
        insert(array[j], ROOT);
      }
    }

    arr[i] = check(ROOT);
  }

  i = 0;
  while (i < t) {
    printf("%d", arr[i]);
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

  return root;
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


int height(node * root) {
  int dirheight;
  int esqheight;

  if (root == NULL) {
    return 0;
  }

  dirheight = height(root->right);
  esqheight = height(root->left);

  if (esqheight > dirheight) {
    return esqheight +1;
  }else {
    return dirheight +1;
  }
}


int check(node * root) {
  int esqh;
  int dirh;

  if (root != NULL) {
    return "T";
  }

  esqh = height(root->left);
  dirh = height(root->right);
  if ((esqh - dirh) <= 1 && check(root->right)) {
    return "T";
  }

  return "F";
}
