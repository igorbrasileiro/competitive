#include <bits/stdc++.h>

using namespace std;

// utility
void print_arr(vector<int> &a) {
  for (int &v: a) {
    printf("%d, ", v);
  }
  printf("\n");
}

// CHANGE
int func(int a, int b) {
  return a + b;
}

void build_sgtree(vector<int> &sgtree, int id, int l, int r, vector<int> &input) {
  if (l == r) {
    sgtree[id] = input[l];
  } else {
    int mid = (l + r) / 2;
    build_sgtree(sgtree, id * 2, l, mid, input);
    build_sgtree(sgtree, id * 2 + 1, mid+1, r, input);
    sgtree[id] = func(sgtree[id * 2], sgtree[id * 2 + 1]);
  }
}

int query(vector<int> &sgtree, int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    // full cover
    return sgtree[id];
  } else if (y < l || x > r) {
    // disjoint interval
    return 0;
  } else {
    int mid = (l + r) / 2;
    return func(query(sgtree, id * 2, l, mid, x, y), query(sgtree, id * 2 + 1, mid+1, r, x, y));
  }
}

void update(vector<int> &sgtree, int id, int l, int r, int pos, int val) {
  if (l == r) {
    sgtree[id] = val;
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid) {
      // pos inside left child
      update(sgtree, id * 2, l, mid, pos, val);
    } else {
      // pos inside right child
      update(sgtree, id * 2 + 1, mid + 1, r, pos, val);
    }
    sgtree[id] = func(sgtree[id * 2], sgtree[id * 2 + 1]);
  }
}

int main() {
  vector<int> input = {1,2,3,4,5};
  vector<int> tree(input.size() * 4);

  build_sgtree(tree, 1, 0, input.size()-1, input);
  print_arr(tree);
  printf("%d\n", query(tree, 1, 1, input.size(), 3, 3));
  printf("%d\n", query(tree, 1, 1, input.size(), 1, 2));
  printf("%d\n", query(tree, 1, 1, input.size(), 1, 3));
  printf("%d\n", query(tree, 1, 1, input.size(), 4, 5));
  update(tree, 1, 1, 5, 3, 10);
  printf("%d\n", query(tree, 1, 1, input.size(), 3, 3));
  printf("%d\n", query(tree, 1, 1, input.size(), 1, 2));
  printf("%d\n", query(tree, 1, 1, input.size(), 1, 3));
  printf("%d\n", query(tree, 1, 1, input.size(), 4, 5));


  return 0;
}
