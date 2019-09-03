#include <bits/stdc++.h>
using namespace std;
 
// utility
void printMatrix(vector< vector<int>> &matrix) {
  for (auto &row: matrix) {
    for (auto &v: row) {
      cout << v << ",";
    }
    cout << endl;
  }
}
 
inline int myLog2(int val) {
  return __builtin_clz(1) - __builtin_clz(val);
}
// finish utility
 
void build_table(vector< vector<int>> &st, int n, vector<int> &input) {
  int k = myLog2(n);
  for (int i = 0; i < n; i++) {
    vector<int> row(k + 1);
    row[0] = input[i];
    st[i] = row;
  }
 
  for (int j = 1; j <= k; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}
 
int query(vector< vector<int>> &st, int l, int r) {
  int maxLogPower = myLog2(r - l + 1);
  return min(st[l][maxLogPower], st[r - (1 << maxLogPower) + 1][maxLogPower]);
}
 
int left_binary_search(vector< vector<int>> &st, int l, int r) {
  int min_x = query(st, r, r);
  int mid;
  int res = r;
  while (l <= r && l >= 0) {
    mid = (l + r) /2;
    if(query(st, mid, r) < min_x) {
      l = mid + 1; // aproxima  
    } else {
      r = mid - 1; // distancia
      res = mid;
    }
  }
  return res;
}
 
int right_binary_search(vector< vector<int>> &st, int l, int r) {
  int min_x = query(st, l, l);
  int mid;
  int res = l;
  while(l <= r) {
    mid = (r + l) / 2;
    if (query(st, l, mid) < min_x) {
      r = mid - 1; // aproxima
    } else {
      l = mid + 1; // distancia
      res = mid;
    }
  }
  return res;
}
 
int main() {
  int n;
  scanf("%d", &n);
  vector<int> input(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &input[i]);
  }
 
  vector< vector<int>> st(n);
  build_table(st, n, input);
  vector<int> result(n, 0);
  // reusing input to output
  for (int i = n - 1; i >= 0; i--) {
    int l = left_binary_search(st, 0, i);
    int r = right_binary_search(st, i, n-1);
    if (result[r - l] < input[i]) {
      result[r - l] = input[i]; // indexado de 0 então nao soma 1
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (result[i] < result[i + 1]) {
      result[i] = result[i + 1];
    }
  }
 
  for (const int c: result) {
    printf("%d ", c);
  } printf("\n");
 
  return EXIT_SUCCESS;
}