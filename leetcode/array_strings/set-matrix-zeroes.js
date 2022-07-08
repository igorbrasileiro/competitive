/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix) {
  let firstRow = false;
  let firstCol = false;

  for (let row = 0; row < matrix.length; row++) {
    for (let col = 0; col < matrix[0].length; col++) {
      if (matrix[row][col] == 0) {
        // check if first row or column has zero to fulfill after fulfill line and columns
        if (row == 0) {
          firstRow = true;
        }
        if (col == 0) {
          firstCol = true;
        }
        // set zeroes at first line and col for respectifve line/col
        matrix[row][0] = 0;
        matrix[0][col] = 0;
      }
    }
  }

  // start from 1, because already has set the 0 at position zero for row/column
  for (let row = 1; row < matrix.length; row++) {
    for (let col = 1; col < matrix[0].length; col++) {
      if (matrix[row][0] == 0 || matrix[0][col] == 0) {
        matrix[row][col] = 0;
      }
    }
  }

  if (firstRow) {
    for (let col = 0; col < matrix[0].length; col++) {
      matrix[0][col] = 0;
    }
  }

  if (firstCol) {
    for (let row = 0; row < matrix.length; row++) {
      matrix[row][0] = 0;
    }
  }
}
