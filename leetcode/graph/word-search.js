function isIndexValid(board, row, col) {
  return row >= 0 && row < board.length && col >= 0 && col < board[0].length;
}

function dfs(board, word, wordIdx, row, col) {
  if (wordIdx == word.length) {
    return true;
  }

  const directions = [
    [0, 1], // right
    [1, 0], // bottom
    [0, -1], // left
    [-1, 0], // up
  ];

  for (const direction of directions) {
    const newRow = row + direction[0];
    const newCol = col + direction[1];
    if (
      isIndexValid(board, newRow, newCol) &&
      board[newRow][newCol] == word[wordIdx]
    ) {
      const char = board[newRow][newCol];
      board[newRow][newCol] = "*";

      const findWord = dfs(board, word, wordIdx + 1, newRow, newCol);
      if (findWord) {
        return true;
      }

      board[newRow][newCol] = char;
    }
  }

  return false;
}

function exist(board, word) {
  for (let row = 0; row < board.length; row++) {
    for (let col = 0; col < board[0].length; col++) {
      if (word[0] == board[row][col]) {
        const char = board[row][col];
        board[row][col] = "*";

        const findWord = dfs(board, word, 1, row, col);
        if (findWord) {
          return true;
        }

        board[row][col] = char;
      }
    }
  }

  return false;
}
