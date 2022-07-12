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

function isSameTree(p, q) {
  if (q == null && p == null) {
    return true;
  }

  if ((p != null && q == null) || (p == null && q != null) || p.val != q.val) {
    return false;
  }

  const left = isSameTree(p.left, q.left);

  if (!left) {
    return false;
  }

  const right = isSameTree(p.right, q.right);

  return right;
}
