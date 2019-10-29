#include <bits/stdc++.h>
using namespace std;

void fullfill(vector< vector<int>> &matrix, int n, int m) {
  matrix[0] = vector<int> (m, INT_MIN);
  for(int i = 1; i < n; i++) {
    matrix[i] = vector<int> (m);
    matrix[i][0] = INT_MIN;
    for(int j = 1; j < m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int main() {
  int n,m;
  scanf("%d %d", &n, &m);
  n++;
  m++;
  vector< vector<int>> m1(n);
  vector< vector<int>> m2(n);
  fullfill(m1, n, m);
  fullfill(m2, n, m);

  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if (m1[i][j] > m2[i][j]) swap(m1[i][j], m2[i][j]); // greedy, get max and min matrix;
    }
  }

  bool possible = true;
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if (m1[i][j] <= m1[i][j-1] || m1[i][j] <= m1[i-1][j]) {
        possible = false;
        break;
      } else if (m2[i][j] <= m2[i][j-1] || m2[i][j] <= m2[i-1][j]) {
        possible = false;
        break;
      }
    }
  }

  string result = possible ? "Possible" : "Impossible";
  cout << result << endl;

  return EXIT_SUCCESS;
}