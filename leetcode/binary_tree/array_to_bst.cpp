#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      if(nums.size() == 0) return NULL;
      return buildTree(1, nums.size(), nums);
    }
    TreeNode* buildTree(int l, int r, vector<int> &nums) {
      int m = ceil((l + r) / 2.0);
      if (l == r) {
         TreeNode *tree = new TreeNode(nums[m - 1]);
         return tree;
      } else {
       TreeNode *tree = new TreeNode(nums[m - 1]);
        if(l < m) {
          tree->left = buildTree(l, m - 1, nums);
        }
        if(m < r) {
          tree->right = buildTree(m + 1, r, nums);
        }
        return tree;
      }
      return NULL;
    }
};

int main() {
  return EXIT_SUCCESS;
}