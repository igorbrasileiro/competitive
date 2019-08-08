#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector< vector<int>> &matrix) {
  for (auto &row: matrix) {
    for (auto &v: row) {
      cout << v << ",";
    }
    cout << endl;
  }
}

int main() {

  int maxn;
  scanf("%d", &maxn);
  vector<int> list(maxn);
  for (int i = 0; i < maxn; i++)  {
    scanf("%d", &list[i]);
  }

// create st
  int k = __builtin_clz(1) - __builtin_clz(maxn);
  vector< vector<int>> st(maxn);

  for (int i = 0; i < maxn; i++) {
    vector<int> line(k + 1, INT_MAX);
    st[i] = line;
    st[i][0] = list[i];
  }

  // build combinations
  for (int j = 1; j <= k; j++) {
    for (int i = 0; i + (1 << j) <= maxn; i++) {
      // get i from back line and get log jump to combine
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  // printMatrix(st);

  int qntQueries, L, R, m;
  scanf("%d", &qntQueries);
  for (int i = 0; i < qntQueries; i++) {
    scanf("%d%d", &L, &R);
    m = __builtin_clz(1) - __builtin_clz(R - L + 1);
    cout << min(st[L][m], st[R - (1 << m) + 1][m]) << endl;
  }

  return 0;
}