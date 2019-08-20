#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX(a,b,c) max(max(a,b),c)

struct Node {
  int left_value = 0;
  ll left_frequency = 0;
  ll frequency = 0;
  int right_value = 0;
  ll right_frequency = 0;
};

Node func(Node &l, Node &r) {
  Node node = Node();
  if (l.right_value == r.left_value) {
    if (l.left_value == l.right_value) {
      node.left_frequency = l.right_frequency + r.left_frequency;
    } else {
      node.left_frequency = l.left_frequency;
    }

    if (r.left_value == r.right_value) {
      node.right_frequency = l.right_frequency + r.left_frequency;
    } else {
      node.right_frequency = r.right_frequency;
    }

    node.frequency = MAX(l.frequency, r.frequency, l.right_frequency+r.left_frequency);
  } else {
    node.frequency = max(l.frequency, r.frequency);
    node.left_frequency = l.left_frequency;
    node.right_frequency = r.right_frequency;
  }

  node.left_value = l.left_value;
  node.right_value = r.right_value;
  return node;
}

void build(vector<Node> &sgtree, int n, int l, int r, vector<int> &input) {
  if (l == r) {
    Node node = Node();
    node.left_frequency = 1;
    node.right_frequency = 1;
    node.frequency = 1;
    node.left_value = input[l - 1];
    node.right_value = input[l - 1];
    sgtree[n] = node;
  } else {
    int m = (l + r) / 2;
    build(sgtree, 2 * n, l, m, input);
    build(sgtree, 2 * n + 1, m + 1, r, input);
    sgtree[n] = func(sgtree[2 * n], sgtree[2 * n + 1]);
  }
}

Node query(vector<Node> &sgtree, int n, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return sgtree[n];
  } else if (y < l || r < x) {
    Node node = Node();
    return node;
  } else {
    int m = (l + r) / 2;
    Node left = query(sgtree, 2 * n, l, m, x, y);
    Node right = query(sgtree, 2 * n + 1, m + 1, r, x, y);
    return func(left, right);
  }
}

int main() {
  int n, q;
  
  scanf("%d%d", &n, &q); 
  while (n) {
    vector<int> input(n);

    for(int i = 0; i < n; i++) {
      scanf("%d", &input[i]);
    }

    vector<Node> sgtree(4 * n, Node());
    build(sgtree, 1, 1, n, input);

    int x, y;
    for(int i = 0; i < q; i++) {
      scanf("%d%d", &x, &y);
      cout << query(sgtree, 1, 1, n, x, y).frequency << endl;
    }
    scanf("%d%d", &n, &q); 
  }
  return EXIT_SUCCESS;
}