#include <bits/stdc++.h>

using namespace std;
// --- UTILITY
void printVector(vector<int> &row) {
  for (auto &v: row) {
    cout << v << ",";
  }
}
void printMatrix(vector< vector<int>> &matrix) {
  for (auto &row: matrix) {
    printVector(row);
    cout << endl;
  }
}

int func(int &a, int &b) {
  return max(a, b);
}

inline int myLog2(int val) {
  return __builtin_clz(1) - __builtin_clz(val);
}
// --- FINISH UTILITY
inline int query(vector< vector<int>> &st, int &L, int &R) {
  int k = myLog2(R - L + 1);
  return func(st[L][k], st[R - (1 << k) + 1][k]);
}

inline void buildInputAndDiff(vector<int> &input, vector<int> &diff) {
  input[0] = -1;
  scanf("%d", &input[1]); //
  for (int i = 2; i < input.size() - 1; i++) {
    scanf("%d", &input[i]);
    diff[i - 2] = input[i] - input[i - 1];
  }
  input[input.size() - 1] = 1000009;
}

inline void buildSparseTable(vector< vector<int>> &st,vector<int> &diff) {
  int n = diff.size();
  int k = myLog2(n);
  for (int i = 0; i < n; i++) {
    vector<int> row(k + 1);
    row[0] = diff[i];
    st[i] = row;
  }

  for (int j = 1; j <= k; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = func(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int table_binary_search(vector<vector<int>> &table, int t_pos, int d) {
    int l = 0, r = t_pos, ans = 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (query(table, mid, t_pos) <= d) {
            r = mid - 1;
        } else {
            ans = mid + 2;
            l = mid + 1;
        }
    }

    return ans;
}

int binary_search(vector<int> &list, int num) {
    int l = 1;
    int r = list.size() - 1;
    int mid;
    while (l <= r) {
        mid = (r + l) / 2;
        if (list[mid] <= num) {
            l = mid + 1;
            if (num < list[mid + 1]) {
                return mid;
            }
        } else if (list[mid] > num) {
            r = mid - 1;
        }
    }
    return mid;
}

int main() {
  int n,m,t,d,q,ans,t_pos, l;
  scanf("%d", &n);
  vector< vector<int>> st(n - 1);
  vector<int> input(n + 2);
  vector<int> diff(n - 1);
  buildInputAndDiff(input, diff);
  // printVector(input);
  // cout << endl;
  // printVector(diff);
  // cout << endl;
  // cout << diff[n-2] << endl;
  buildSparseTable(st, diff);

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &t, &d);
    t_pos = binary_search(input, t) - 2;
    ans = table_binary_search(st, t_pos, d);
    printf("%d\n", ans);
  }
  return 0;
} 