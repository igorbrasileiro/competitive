#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair<int, int>

bool get_cnds(vector< vector<pii>> &adjs, int v, bool flag, unordered_set<int> &cnds, vector<bool> &visited) {
  bool res = false;
  visited[v] = true;
  
  if (flag && adjs[v].size() == 1) {
    cnds.insert(v);
    return true;
  }
  
  for(pii adj: adjs[v]) {
    if (!visited[adj.first]) {
      res = get_cnds(adjs, adj.first, adj.second == 2 ? true : false, cnds, visited) || res; 
    }
  }

  if (flag && !res) {
    cnds.insert(v);
    res = true;
  }

  return res;
}

int main() {
  int n, a, b, c;
  scanf("%d", &n);
 
  pii p;
  vector< vector<pii>> adjs(n+1);
  vector<bool> visited(n+1, false);
  for(int i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &a, &b, &c);
    p = mp(b,c);
    adjs[a].push_back(p);
    p = mp(a, c);
    adjs[b].push_back(p);
  }

  unordered_set<int> cnds;
  
  get_cnds(adjs, 1, false, cnds, visited); 
  printf("%d\n", (int) cnds.size());
  for(auto it = cnds.begin(); it != cnds.end(); ++it) {
    printf("%d ", *it);
  } printf("\n");

  return EXIT_SUCCESS;
}
