#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

  TreeNode* bstToGst(TreeNode* root) {
    bstToGst(root, 0);
    return root;
  }
      
  int bstToGst(TreeNode* root, int parentVal) {
    if (root->right != NULL) {
      parentVal = bstToGst(root->right, parentVal);
    }
    parentVal += root->val;
    root->val = parentVal;
    if (root->left != NULL) {
      parentVal += (bstToGst(root->left, parentVal) - parentVal);
    }
    return parentVal;
  }