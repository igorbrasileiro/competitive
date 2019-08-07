#include <bits/stdc++.h>
using namespace std;

void dfs(vector< vector<int>> &rooms, vector<bool> &visited, int node) {
  visited[node] = true;

  for(int nextNode: rooms[node]) {
    if (!visited[nextNode]) {
      dfs(rooms, visited, nextNode);
    }
  }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
  vector<bool> visited(rooms.size(), false);

  dfs(rooms, visited, 0);
  bool result = true;
  for(bool visitedroom: visited) {
    result = result && visitedroom;
  }

  return result;
}

int main() {
  vector< vector<int>> rooms = {{1},{2},{3},{}};
  cout << canVisitAllRooms(rooms) << endl;

  return EXIT_SUCCESS;
}