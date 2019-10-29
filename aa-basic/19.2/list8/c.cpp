#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector< unordered_set<int>> adjs(4002, unordered_set<int> ());
  vector< pair<int, int>> con;
  int v1,v2;
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &v1, &v2);
    adjs[v1].insert(v2);
    adjs[v2].insert(v1);
    con.push_back({ v1, v2 });
  }

  int ans = INT_MAX;
  for(int i = 0; i < m; i++) {
    v1 = con[i].first;
    v2 = con[i].second;

    for (int j = 1; j < n + 1; j++) {
      if (j != v1 && j != v2) {
        if (adjs[j].find(v1) != adjs[j].end() && adjs[j].find(v2) != adjs[j].end()) {
          ans = min(ans, (int) (adjs[j].size() + adjs[v1].size() + adjs[v2].size()));
        }
      }
    }
  }

  ans = ans == INT_MAX ? -1 : ans - 6;
  printf("%d\n", ans);


  return EXIT_SUCCESS;
}