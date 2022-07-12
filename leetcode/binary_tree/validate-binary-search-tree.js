/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function inOrderBST(node, list) {
  if (node.left != null) {
    inOrderBST(node.left, list);
  }

  list.push(node.val);

  if (node.right != null) {
    inOrderBST(node.right, list);
  }
}

function isValidBST(root) {
  const list = [];
  inOrderBST(root, list);
  for (let idx = 1; idx < list.length; idx++) {
    if (list[idx - 1] >= list[idx]) {
      return false;
    }
  }
  return true;
}
