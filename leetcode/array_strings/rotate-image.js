/**
 Do not return anything, modify matrix in-place instead.
 */
function rotate(matrix) {
  const n_1 = matrix.length - 1;

  for (let line = 0; line < Math.trunc(matrix.length + 1 / 2); line++) {
    for (let col = line; col < n_1 - line; col++) {
      const topLeft = matrix[line][col];
      matrix[line][col] = matrix[n_1 - col][line]; // top left = bottom left
      matrix[n_1 - col][line] = matrix[n_1 - line][n_1 - col]; // bottom left = bottom right
      matrix[n_1 - line][n_1 - col] = matrix[col][n_1 - line]; // bottom right = top left
      matrix[col][n_1 - line] = topLeft; // top right = top left
    }
  }
}
