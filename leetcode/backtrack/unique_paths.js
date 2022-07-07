// https://www.geeksforgeeks.org/factorial-of-large-numbers-using-logarithmic-identity/
// total combinations with repetition is = (m + n)! / m! * n!
// For this questions, m and n are decreased by 1, so
// e ^ Sum (ln (m - 1 + n - 1)) / e ^ Sum (ln (m - 1 to 1)) * e ^ Sum (ln (n - 1 to 1))
// Doing simplifications the result is = e ^ (Sum ln(m - 1 to n) - Sum ln (n - 1 to 1))
function uniquePaths(m, n) {
  const max = Math.max(m, n)
  const min = Math.min(m, n)
  const max_1 = max - 1
  const min_1 = min - 1
  let dividend = 0;
    let divisor = 0
    
  for (let val = (max_1 + min_1); val >= max; val--) {
      dividend += Math.log(val)
  }
  
  for (let val = 1; val <= min_1; val++) {
      divisor += Math.log(val)
  }
    
  return Math.pow(Math.E, dividend - divisor)
};