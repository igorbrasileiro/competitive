#include <bits/stdc++.h>
using namespace std;

// B - Interval Product 

// utility
void print_arr(vector<int> &a) {
  for (int &v: a) {
    printf("%d, ", v);
  }
  printf("\n");
}

// CHANGE
char func(char a, char b) {
  if (a == '0' || b == '0') {
    return '0';
  } else if (a == '-' && b == '-') {
    return '+';
  } else if (a == '-' || b == '-') {
    return '-';
  } else {
    return '+';
  }
}

void build_sgtree(vector<char> &sgtree, int id, int l, int r, vector<char> &input) {
  if (l == r) {
    sgtree[id] = input[l-1];
  } else {
    int mid = (l + r) / 2;
    build_sgtree(sgtree, id * 2, l, mid, input);
    build_sgtree(sgtree, id * 2 + 1, mid+1, r, input);
    sgtree[id] = func(sgtree[id * 2], sgtree[id * 2 + 1]);
  }
}

char query(vector<char> &sgtree, int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return sgtree[id];
  } else if (y < l || x > r) {
    return '+';
  } else {
    int mid = (l + r) / 2;
    return func(query(sgtree, id * 2, l, mid, x, y), query(sgtree, id * 2 + 1, mid+1, r, x, y));
  }
}

void update(vector<char> &sgtree, int id, int l, int r, int pos, int val) {
  if (l == r) {
    sgtree[id] = val;
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid) {
      update(sgtree, id * 2, l, mid, pos, val);
    } else {
      update(sgtree, id * 2 + 1, mid + 1, r, pos, val);
    }
    sgtree[id] = func(sgtree[id * 2], sgtree[id * 2 + 1]);
  }
}

int main() {
  int n, k;
  while(scanf("%d%d", &n, &k) != EOF) { 
    vector<char> input(n);
    vector<char> tree(4 * n);
    int aux;
    for (int i = 0; i < n; i++) {
      scanf("%d", &aux);
      if (aux == 0) {
        input[i] = '0';
      } else if (aux < 0) {
        input[i] = '-';
      } else {
        input[i] = '+';
      }
    }
    build_sgtree(tree, 1, 1, n, input);
    int x, y, ans;
    char c;
    for (int i = 0; i < k; i++) {
      cin >> c;
      scanf("%d%d", &x, &y);
      // cout << c;
      if (c == 'C') {
        if (y == 0) {
          update(tree, 1, 1, n, x, '0');
        } else if (y < 0) {
          update(tree, 1, 1, n, x, '-');
        } else {
          update(tree, 1, 1, n, x, '+');
        }
      } else if (c == 'P') {
        cout << query(tree, 1, 1, n, x, y);
      }
    }
    printf("\n");
  }
  return 0;
}
