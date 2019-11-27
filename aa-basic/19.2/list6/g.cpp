#include <bits/stdc++.h>
using namespace std;

void dfs(vector< vector< pair<char, bool>>> &matrix, int x, int y, int maxX, int maxY) {
  // verificar se já foi visitado
  matrix[x][y].second = true;
  for(int i = max(0, x - 1); i < min(x + 2, maxX); i++) {
    for(int j = max(0, y - 1); j < min(y + 2, maxY); j++) {
      if (matrix[i][j].first == '@' && !matrix[i][j].second) {
        dfs(matrix, i, j, maxX, maxY);
      }    
    }
  }
  
}

int main() {
  int n,m;
  char c;
  // todo while
  scanf("%d %d", &n, &m);
  getchar();
  while(m) {
    vector< vector< pair<char, bool>>> matrix(n);
    for(int i = 0; i < n; i++) {
      matrix[i] = vector<pair<char, bool>> (m);
      for (int j = 0; j < m; j++) {
        scanf("%c", &c);
        matrix[i][j] = make_pair(c, false);
      }
      getchar();
    }
  
    int count = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(matrix[i][j].first == '@' && !matrix[i][j].second) {
          dfs(matrix, i, j, n, m);
          count++;
        }
      }
    }

    printf("%d\n", count);
    scanf("%d %d", &n, &m);
    getchar();
  }
  return EXIT_SUCCESS;
}