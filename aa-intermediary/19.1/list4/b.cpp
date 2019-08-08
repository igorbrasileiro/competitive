#include <bits/stdc++.h>

#define ll long long

using namespace std;

// https://codeforces.com/problemset/problem/242/E

struct node {
  vector<int> lazy;
  vector<int> numb;
};

void print_arr(vector<node> &array) {
  for (auto &node: array) {
    cout << '[';
    for(auto &c: node.numb) {
      cout << c << ',';
    }
    cout << "] ";
  }
  cout << endl;
}

vector<int> decToBinary(int n) { 
  vector<int> numb(20);
  int clz1 = __builtin_clz(1);
  int i = clz1 - __builtin_clz(n); 
  while (n > 0) { 
    numb[i] = 1; 
    n -= 1 << i;
    if (n > 0) { // 0 is not a valid value for clz
      i = clz1 - __builtin_clz(n);
    }
  } 

  return numb;
}

ll binaryToDec(vector<int> numb) {
  ll res = 0;
  for (int i = 0; i < 20; i++) {
    res += (ll) numb[i] << i;
  }
  return res;
}

void func(vector<int> &root, vector<int> &left, vector<int> &right) {
  for (int i = 0; i < 20; i++) {
    root[i] = left[i] + right[i];
  }
}

void propagate(vector<node> &sgtree, int id, int l, int r) {
  // caso ocorra 2 updates no mesmo nó?
  if (l != r) {
    for (int i = 0; i < 20; i++) {
      sgtree[id * 2].lazy[i] = sgtree[id].lazy[i] ^ sgtree[id * 2].lazy[i];
      sgtree[id * 2 + 1].lazy[i] = sgtree[id].lazy[i] ^ sgtree[id * 2 + 1].lazy[i];
      // calc for node;
      if(sgtree[id].lazy[i] != 0) {
        sgtree[id].numb[i] = (r - l + 1) - sgtree[id].numb[i];
      }
      sgtree[id].lazy[i] = 0;
    }
  } else {
    for (int i = 0; i < 20; i++) {
      if(sgtree[id].lazy[i] != 0) {
        sgtree[id].numb[i] = (r - l + 1) - sgtree[id].numb[i];
      }
      sgtree[id].lazy[i] = 0;
    }
  }
}

void build (vector<node> &sgtree, int id, int l, int r, vector<int> &input) {
  if (l == r) {
    sgtree[id].lazy = vector<int> (20);
    sgtree[id].numb = decToBinary(input[l - 1]); // input indexed by 0
  } else {
    int mid = (l + r) / 2;
    build(sgtree, 2 * id, l, mid, input);
    build(sgtree, 2 * id + 1, mid + 1, r, input);
    sgtree[id].lazy = vector<int> (20);
    sgtree[id].numb = vector<int> (20);
    func(sgtree[id].numb, sgtree[2 * id].numb, sgtree[2 * id + 1].numb);
  }
}

ll query(vector<node> &sgtree, int id, int l, int r, int x, int y) {
  if (x <= l and r <= y) {
    propagate(sgtree, id, l, r);
    return binaryToDec(sgtree[id].numb);
  } else if (x > r || y < l) {
    // should have a propagete here, but without get accepted
    // propagate(sgtree, id, l, r);
    return 0;
  } else {
    propagate(sgtree, id, l, r);
    int m = (l + r) / 2;
    return query(sgtree, 2 * id, l, m, x, y) + query(sgtree, 2 * id + 1, m + 1, r, x, y);
  }
}

void update(vector<node> &sgtree, int id, int l, int r, int x, int y, vector<int> &val) {
  if (x <= l and r <= y) {
    for (int i = 0; i < 20; i++) {
      sgtree[id].lazy[i] = sgtree[id].lazy[i] ^ val[i];
    }
    propagate(sgtree, id, l, r);
  } else if (x > r || y < l) {
    // should have a propagete here, but without get accepted
    propagate(sgtree, id, l, r);
  } else {
    propagate(sgtree, id, l, r);
    int m = (l + r) / 2;
    update(sgtree, 2 * id, l, m, x, y, val);
    update(sgtree, 2 * id + 1, m + 1, r, x, y, val);
    func(sgtree[id].numb, sgtree[2 * id].numb, sgtree[2 * id + 1].numb);
  }
}

int main() {
  int n, val, q, op, x, y;
  scanf("%d", &n);
  vector<int> input(n);
  
  for (int i = 0; i < n; i++) scanf("%d", &input[i]);
  
  vector<node> sgtree(n * 4);
  build(sgtree, 1, 1, n, input);
  // print_arr(sgtree);

  vector<int> binVal;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &y);
      cout << query(sgtree, 1, 1, n, x, y) << endl;
    } else {
      scanf("%d%d%d", &x, &y, &val);
      binVal = decToBinary(val);
      update(sgtree, 1, 1, n, x, y, binVal);
    }
  }

  return 0;
}