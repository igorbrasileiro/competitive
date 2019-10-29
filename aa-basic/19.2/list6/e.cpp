#include <bits/stdc++.h>
using namespace std;

void dfs(vector< vector<int>> &graph, vector<bool> &visited, int node) {
  visited[node] = true;
  for (const int adj: graph[node]) {
    if (!visited[adj])
      dfs(graph, visited, adj);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  vector<int> x(n+1), y(n+1);
  for (int i = 1; i < n + 1; i++) scanf("%d %d", &x[i], &y[i]);

  vector< vector<int>> graph (n+1);
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (x[i] == x[j] || y[i] == y[j]) {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }

  vector<bool> visited(n + 1);
  int tree_count = 0;
  for (int i = 1; i < n + 1; i++) {
    if (!visited[i]) {
      tree_count++;
      dfs(graph, visited, i);
    }
  }

  printf("%d\n", tree_count - 1);

  return EXIT_SUCCESS;
}