#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/flipping-an-image/

int main() {
  int input[][4] = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
  
  vector<vector<int>> a;

  for (auto &line: input) {
    vector<int> aux (line, line + sizeof(line) / sizeof(int));
    a.push_back(aux);
  }

  cout << a[0][1] << endl;

  return 0;
}