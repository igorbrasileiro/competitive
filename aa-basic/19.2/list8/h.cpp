#include <bits/stdc++.h>
using namespace std;

int resp[1001], p[1000001][2];
bool flags[1001];
int main(){
  int n;
  scanf("%d",&n);
  n *= 2;
  int x;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      scanf("%d", &x);
      p[x][0] = i;
      p[x][1] = j;
    }
  }

  flags[0] = 1;
  for (int i = 1000000; i > 0; i--) {
    if (!flags[p[i][0]] && !flags[p[i][1]]) {
      flags[p[i][0]] = 1;
      flags[p[i][1]] = 1;
      resp[p[i][0]] = p[i][1];
      resp[p[i][1]] = p[i][0];
    }
  }
  for(int i = 1; i <= n; i++) {
    if(i > 1) printf(" ");
    printf("%d",resp[i]);
  }
  printf("\n");
  return 0;
}
