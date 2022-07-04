function spiralOrder(matrix) {
  const height = matrix.length;
  const width = matrix[0].length;
  let numbOfCels = width * height;
  const result = [];
  let line = 0;
  let col = 0;
  let level = 0;
  let direction = 0; // 0 right, 1 down, 2 left, 3 up

  while (numbOfCels > 0) {
    result.push(matrix[line][col]);
    numbOfCels -= 1;

    // next step
    // going right
    if (direction === 0) {
      if (width - 1 - level === col) {
        direction = 1; // go down
        line += 1;
      } else {
        col += 1;
      }
      // going down
    } else if (direction === 1) {
      if (height - 1 - level === line) {
        direction = 2; // go left
        col -= 1;
      } else {
        line += 1;
      }
      // going left
    } else if (direction === 2) {
      if (level === col) {
        direction = 3;
        line -= 1;
      } else {
        col -= 1;
      }
      // going up
    } else {
      if (line === level + 1) {
        level += 1; // Increase level
        direction = 0;
        col += 1;
      } else {
        line -= 1;
      }
    }
  }

  return result;
}
