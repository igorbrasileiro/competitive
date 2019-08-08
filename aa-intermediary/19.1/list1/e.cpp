#include <bits/stdc++.h>

using namespace std;

// E - Connect - cf
bool isValidIndex(int x, int y, int size) {
  if(x < 0 || x >= size) {
    return false;
  } else if (y < 0 || y >= size) {
    return false;
  }

  return true;
}

void fullfillSet(vector<vector<char>> &matrix, vector<pair<int, int>> &set, int size, int x, int y) {
  if (matrix[x][y] == '0') {
    set.push_back(make_pair(x,y));
    matrix[x][y] = '1';

    if (isValidIndex(x+1, y, size)) { // go bot
      fullfillSet(matrix, set, size, x+1, y);
    }
 
    if (isValidIndex(x-1, y, size)) { // go up
      fullfillSet(matrix, set, size, x-1, y);
    }

    if (isValidIndex(x, y+1, size)) { // go right
      fullfillSet(matrix, set, size, x, y+1);
    }

    if (isValidIndex(x, y-1, size)) { // go right
      fullfillSet(matrix, set, size, x, y-1);
    }

  }
}

int main() {
  int n;
  pair<int, int> coord_1, coord_2;
  vector<pair<int, int>> land_1, land_2;

  scanf("%d", &n);
  scanf("%d%d", &coord_1.first, &coord_1.second);
  scanf("%d%d", &coord_2.first, &coord_2.second);
  
  vector<vector<char>> matrix(n, vector<char>(n));
  char c;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> c;
      matrix[i][j] = c;
    }
  }

  fullfillSet(matrix, land_1, matrix.size(), coord_1.first-1, coord_1.second-1);
  int ans = 10000;
  for(int i = 0; i < land_1.size(); i++) {
    if (land_1[i].first == coord_2.first-1 && land_1[i].second == coord_2.second-1) {
      ans = 0;
    }
  }

  if (ans > 0) {
    fullfillSet(matrix, land_2, matrix.size(), coord_2.first-1, coord_2.second-1);
  
    for(int i = 0; i < land_1.size(); i++) {
      for (int j = 0; j < land_2.size(); j++) {
        n = ((land_1[i].first - land_2[j].first)*(land_1[i].first - land_2[j].first)) 
                  + ((land_1[i].second - land_2[j].second)*(land_1[i].second - land_2[j].second));
        ans = min(n, ans);
      }
    }
  }

  cout << ans << endl;

  return 0;
}