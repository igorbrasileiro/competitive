#include <bits/stdc++.h>
using namespace std;

// A - Factory Repairs
bool F = false;
bool T = true;
#define ll long long

void build(vector< pair<ll, ll>> &sgtree, int node, int l, int r, int &minValue) {
  if (l == r) {
    sgtree[node] = make_pair(0, 0);
  } else {
    int m = (l + r) / 2;
    int leftChild = 2 * node;
    int rightChild = leftChild + 1;
    build(sgtree, leftChild, l, m, minValue);
    build(sgtree, rightChild, m + 1, r, minValue);
    sgtree[node] = make_pair(sgtree[leftChild].first + sgtree[rightChild].first, 0);
  }
}

ll query(vector< pair<ll, ll>> &sgtree, int node, int l, int r, int x, int y, bool &isMinQuery) {
  if (x <= l && r <= y) {
    if (isMinQuery) {
      return sgtree[node].first;
    } else {
      return sgtree[node].second;
    }
  } else if (y < l || x > r) {
    return 0;
  } else {
    int m = (l + r) / 2;
    int leftChild = 2 * node;
    int rightChild = leftChild + 1;
    return query(sgtree, leftChild, l, m, x, y, isMinQuery) + query(sgtree, rightChild, m+1, r, x, y, isMinQuery);
  }
}

void update(vector< pair<ll, ll>> &sgtree, int node, int l, int r, int &minValue, int &maxVal, int &pos, int &val) {
  if (l == r && l == pos) {
    sgtree[node].second = min(sgtree[node].second + val, (ll) maxVal);
    sgtree[node].first = min((ll)minValue, sgtree[node].second);
  } else {
    int m = (l + r) / 2;
    if (pos <= m) {
      update(sgtree, 2 * node, l, m, minValue, maxVal, pos, val);
    } else {
      update(sgtree, 2 * node + 1, m + 1, r, minValue, maxVal, pos, val);
    }

    sgtree[node].second = sgtree[2 * node].second + sgtree[2 * node + 1].second;
    sgtree[node].first = sgtree[2 * node].first + sgtree[2 * node + 1].first;
  }
}

void print_m(vector< pair<ll, ll>> &sgtree) {
  for (int i = 0; i < sgtree.size(); i ++) {
    if (sgtree[i].first != 0) {
      cout << "(" << sgtree[i].first << ", " << sgtree[i].second << ") ";
    }
  } cout << endl;
}

int main() {
  int n, k, a, b, q;
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  vector< pair<ll,ll>> sgtree (4 * n); // pair = <mim, max(sum order)>
  build(sgtree, 1, 1, n, b);

  // print_m(sgtree);

  int op, d, ai, sumDays;
  ll val;
  for (int i = 0; i < q; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &d, &ai);
      update(sgtree, 1, 1, n, b, a, d, ai);
      // print_m(sgtree);
    } else {
      scanf("%d", &d);
      sumDays = d + k;
      if (d == 1) {
        val = query(sgtree, 1, 1, n, sumDays, n, F); // from finish maintance day + 1 till last day
        // cout << sumDays << " "<< val << endl;
      } else {
        // max - max(from day d, end day) - min(day 1, to day (d - 1));
        // int mini = query(sgtree, 1, 1, n, 1, d - 1, T);
        val = query(sgtree, 1, 1, n, 1, d - 1, T);
        if (!(sumDays > n)) {
          val += query(sgtree, 1, 1, n, min(sumDays, n), n, F);
        }
        // cout << d -1 << " " << min(sumDays, n)<< " " << mini << " " << val << endl;
        // val += mini;
      }

      cout << val << endl;
    }
  }

  return EXIT_SUCCESS;
}