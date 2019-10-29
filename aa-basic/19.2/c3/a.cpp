#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w; // height width
  scanf("%d %d", &h, &w);
  vector<int> horizontal(w);
  vector<int> vertical(h);
  vector< vector<int>> matrix(h);
  for (int i = 0; i < h; i++) {
    matrix[i] = vector<int> (w, -1);
  }

  for (int i = 0; i < w; i++) {
    scanf("%d", &horizontal[i]);
  }

  for (int i = 0; i < h; i++) {
    scanf("%d", &vertical[i]);
  }

  int c;
  for (int i = 0; i < w; i++) {
    c = horizontal[i];
    for (int j = 0; j < c; j++) {
      matrix[j][i] = 1;
    }
    if (c < h) {
      matrix[c][i] = 0;
    }
  }

  long long ans = 0;
  for (int i = 0; i < h; i++) {
    c = vertical[i];
    if (matrix[i][c] == 0) {} // ?!
    for (int j = 0; j < c; j++) {
      matrix[i][j]
    }
  }

  return EXIT_SUCCESS;
}