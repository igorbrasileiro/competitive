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

function levelOrder(root) {
  if (root == null) {
    return [];
  }
  let currentQueue = [root];
  let auxQueue = [];
  const result = [];

  while (currentQueue.length > 0) {
    result.push([]);
    while (currentQueue.length > 0) {
      const node = currentQueue.shift();
      result[result.length - 1].push(node.val);

      if (node.left != null) {
        auxQueue.push(node.left);
      }
      if (node.right != null) {
        auxQueue.push(node.right);
      }
    }
    currentQueue = auxQueue;
    auxQueue = [];
  }

  return result;
}
