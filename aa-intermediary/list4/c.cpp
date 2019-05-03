#include <bits/stdc++.h>

using namespace std;

// Multiples of 3 
struct node {
  int lazy;
  vector<int> mult; // alterar pra vector
};

void print_arr(vector<node> &sgtree) {
  for (int i = 0; i < sgtree.size(); i++) {
    cout << '[';
    for(auto &c: sgtree[i].mult) {
      cout << c << ',';
    }
    cout << "] ";
  }
  cout << endl;
}

void func(vector<int> &mults, vector<int> &a, vector<int> &b) {
  mults[0] = a[0] + b[0];
  mults[1] = a[1] + b[1];
  mults[2] = a[2] + b[2];
}

void shiftRight(vector<int> &mults) {
  int aux = mults[2];
  mults[2] = mults[1];
  mults[1] = mults[0];
  mults[0] = aux;
}

void propagate(vector<node> &sgtree, int id, int L, int R) {
  if (L != R) {
    sgtree[2 * id].lazy += sgtree[id].lazy;
    sgtree[2 * id + 1].lazy += sgtree[id].lazy;
  }
  for (int i = 0; i < sgtree[id].lazy % 3; i++) {
    shiftRight(sgtree[id].mult);
  }
  sgtree[id].lazy = 0;
}

void build(vector<node> &sgtree, int id, int L, int R) {
  if (L == R) {
    sgtree[id].lazy = 0;
    sgtree[id].mult = {1, 0, 0};
  } else {
    int mid = (L + R) / 2;
    build(sgtree, 2 * id, L, mid);
    build(sgtree, 2 * id + 1, mid + 1, R);
    sgtree[id].lazy = 0;
    sgtree[id].mult = {0,0,0};
    func(sgtree[id].mult, sgtree[2 * id].mult, sgtree[2 * id + 1].mult);
  }
}

int query(vector<node> &sgtree, int id, int L, int R, int X, int Y) {
  if (X <= L and R <= Y) {
    propagate(sgtree, id, L, R);
    return sgtree[id].mult[0];
  } else if (X > R || Y < L) {
    // should have a propagete here, but without get accepted
    return 0;
  } else {
    propagate(sgtree, id, L, R);
    int m = (L + R) / 2;
    return query(sgtree, 2 * id, L, m, X, Y) + query(sgtree, 2 * id + 1, m + 1, R, X, Y);
  }
}

void update(vector<node> &sgtree, int id, int L, int R, int X, int Y) {
  if (X <= L and R <= Y) {
    sgtree[id].lazy += 1;
    propagate(sgtree, id, L, R);
  } else if (X > R || Y < L) {
    propagate(sgtree, id, L, R);
    return;
  } else {
    propagate(sgtree, id, L, R);
    int m = (L + R) / 2;
    update(sgtree, 2 * id, L, m, X, Y);
    update(sgtree, 2 * id + 1, m + 1, R, X, Y);
    func(sgtree[id].mult, sgtree[2 * id].mult, sgtree[2 * id + 1].mult);
  }
}

int main() {
  int N, Q, OP, A, B;
  scanf("%d%d", &N, &Q);
  vector<node> sgtree(N * 4);
  build(sgtree, 1, 1, N);
  // print_arr(sgtree);

  for (int i = 0; i < Q; i++) {
    scanf("%d%d%d", &OP, &A, &B);
    if (OP == 1) {
      printf("%d\n", query(sgtree, 1, 1, N, A + 1, B + 1));
    } else {
      update(sgtree, 1, 1, N, A + 1, B + 1);
      // printf("%d %d\n", A + 1, B + 1);
      // print_arr(sgtree);
    }
  }

  return 0;
}