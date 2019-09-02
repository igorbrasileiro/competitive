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

int left_binary_search(vector< vector<int>> &st, int pos_x) {
  int l = pos_x / 2;
  int min_x = query(st, pos_x, pos_x);
  while (l <= pos_x && l >= 0) {
    cout << l << endl;
    if(query(st, l, pos_x) < min_x) {
      l = (l + pos_x) / 2;
    } else {
      if (l == 0) {
        break;
      }
      // se a 
      if (query(st, l - 1, pos_x) == min_x) {
        l = (l / 2);
      } else {
        break;
      }
    }
  }
  return max(0, l);
}

int right_binary_search(vector< vector<int>> &st, int pos_x, int max) {
  int r = (pos_x + max) / 2;
  int min_x = query(st, pos_x, pos_x);
  while(r < max && pos_x <= r) {
    cout << r << endl;
    if(query(st, pos_x, r) < min_x) {
      r = (pos_x + r) / 2;
    } else {
      if (r == max) {
        break;
      }
      if (query(st, pos_x, r + 1) == min_x) {
        r = (r + max) / 2;
      } else {
        break;
      }
    }
  }
  return r;
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

  // reusing input to output
  for (int i = n - 1; i >= 0; i--) {
    input[i] = 0;
    cout << i << " left" << endl;
    int l = left_binary_search(st, i);
    cout << "right" << endl;
    int r = right_binary_search(st, i, n);
    cout << "dsada" << l << " " << r << endl;
  }
  return EXIT_SUCCESS;
}