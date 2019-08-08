#include <bits/stdc++.h>
using namespace std;

// C - Maximum Sum 

#define ll long long

pair<int, int> my_null = make_pair(INT_MIN, INT_MIN);

pair<int,int> func(vector<int> &twoPairs) {
  sort(twoPairs.begin(), twoPairs.end());

  return make_pair(twoPairs[2], twoPairs[3]);
}

void buildTree(vector<pair<int,int>> &sgtree, int node, int l, int r, vector<int> &input) {
  if (l == r) {
    sgtree[node] = make_pair(input[l - 1], INT_MIN);
  } else {
    int m = (l + r) / 2;
    int leftNode = node * 2;
    int rightNode = node * 2 + 1;
    buildTree(sgtree, leftNode, l, m, input);
    buildTree(sgtree, rightNode, m + 1, r, input);
    vector<int> twoPairs = {sgtree[leftNode].first, sgtree[leftNode].second, sgtree[rightNode].first, sgtree[rightNode].second};
    sgtree[node] = func(twoPairs);
  }
}

pair<int, int> query(vector<pair<int,int>> &sgtree, int node, int l, int r, int &x, int &y) {
  if (x <= l && r <= y) {
    return sgtree[node];
  } else if(r < x || l > y) {
    return my_null;
  } else {
    int m = (l + r) / 2;
    pair<int, int> p1 = query(sgtree, node * 2, l, m, x, y);
    pair<int, int> p2 = query(sgtree, node * 2 + 1, m + 1, r, x, y);
    vector<int> twoPairs = {p1.first, p1.second, p2.first, p2.second};
    return func(twoPairs);
  }
}

void update(vector<pair<int,int>> &sgtree, int node, int l, int r, int &pos, int &val) {
  if (l == r) {
    sgtree[node].first = val;
  } else {
    int m = (l + r) / 2;
    int leftNode = node * 2;  
    int rightNode = node * 2 + 1;
    if (pos <= m) {
      update(sgtree, leftNode, l, m, pos, val);
    } else {
      update(sgtree, rightNode, m + 1, r, pos, val);
    }
    vector<int> twoPairs = {sgtree[leftNode].first, sgtree[leftNode].second, sgtree[rightNode].first, sgtree[rightNode].second};
    sgtree[node] = func(twoPairs);
  }
}


int main() {
  int n,q, x, y;
  scanf("%d", &n);

  vector<pair<int,int>> sgtree(4 * n);
  vector<int> input(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &input[i]);
  
  buildTree(sgtree, 1, 1, n, input);

  scanf("%d\n", &q);
  char OP;
  pair<int, int> p;
  for (int i = 0; i < q; i++) {
    scanf("%c %d %d\n", &OP, &x, &y);
    if (OP == 'Q') {
      p = query(sgtree, 1, 1, n, x, y);
      cout << p.first + p.second << endl;
    } else {
      update(sgtree, 1, 1, n, x, y);
    }
  }

  return EXIT_SUCCESS;
}