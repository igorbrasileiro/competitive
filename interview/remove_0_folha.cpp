#include <bits/stdc++.h>
using namespace std;

struct Tree {
  int value;
  Tree *left;
  Tree *right;
};

Tree* remove(Tree *tree) {
  if (tree->value == 0 && tree->left == NULL && tree->right == NULL) {
    return NULL;
  }

  if (tree->left != NULL) {
    tree->left = remove(tree->left);
  }

  if (tree->right != NULL) {
    tree->right = remove(tree->right);
  }

  if (tree->value == 0 && tree->left == NULL && tree->right == NULL) {
    return NULL;
  } else {
    return tree;
  }
}

int main() {
   Tree *root = new Tree;
   root->value = 32;
   
   Tree *left = new Tree;
   left->value = 9;
   root->left = left;

   Tree *leftright = new Tree;
   leftright->value = 5;
   Tree *leftleft = new Tree;
   leftleft->value = 0;
   left->left = leftleft;
   left->right = leftright;

   Tree *right = new Tree;
   right->value = 0;
   root->right = right;
  
   Tree *rightleft = new Tree;
   rightleft->value = 0;
   Tree *rightright = new Tree;
   rightright->value = 0;
   right->left = rightleft;
   right->right = rightright;


  root = remove(root);
  if(root->right == NULL) {
    printf("TA OK MANO! no direita\n");
  }
  if(root->left->left == NULL) {
    printf("no esquerda\n");
  }

  return 0;
}
