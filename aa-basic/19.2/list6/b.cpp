#include <bits/stdc++.h>
using namespace std;

bool dfs(vector< vector<int>> &adjs, int v, int f, vector<bool> &visited) {
  if (visited[v]) return false;

  visited[v] = true;
  bool result = true;
  for (int adj: adjs[v]) {
    if(adj != f) {
  //  printf("v: %d - adj: %d - f: %d\n", v, adj, f);
      result = result && dfs(adjs, adj, v, visited);
    }
  }
//  printf("result: %d - v: %d\n", result, v);
  return result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector< vector<int>> adjs(n+1);
  
  int va, vb;
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &va, &vb);
    adjs[va].push_back(vb);
    adjs[vb].push_back(va);
  }

  vector<bool> visited(n+1, false);
  // fazer dfs returnando bool && todo no está visitado no final;
  bool isTree = dfs(adjs, 1, -1, visited);
  // cout << isTree << endl;
  for(int i = 1; i < n+1; i++) {
    isTree = isTree && visited[i];
  }

  string s = isTree ? "YES" : "NO";
  cout << s << endl;
  return EXIT_SUCCESS;
}
