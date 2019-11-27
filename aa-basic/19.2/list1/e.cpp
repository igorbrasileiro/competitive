#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  int res = min(n, m);
  if (res % 2) {
    printf("Akshat");
  } else {
    printf("Malvika");
  }

  return EXIT_SUCCESS;
}