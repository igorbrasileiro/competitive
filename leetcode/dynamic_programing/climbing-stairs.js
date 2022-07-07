/**
 * pay attention with the ()
 * for n = 1 -> 1
 * for n = 2 -> (1) - 1
 *              2
 * total = 2
 * for n = 3 -> (1 - 1) - 1
 *              (2) - 1
 *              1 - 2
 * total = 3
 * for n = 4 -> (1 - 1 - 1)- 1
 *              (2 - 1) - 1
 *              (1 - 2) - 1
 *              1 - 1 - 2
 *              2 - 2
 * total = 5
 * */ 

function climbStairs(n) {
  let prev = 1
  let curr = 1
  let next;
  
  while (n > 1) {
      next = curr + prev
      prev = curr
      curr = next
      n -= 1
  }
  
  return curr
};