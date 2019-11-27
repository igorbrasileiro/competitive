#include <bits/stdc++.h>
using namespace std;

int main() {

  int x, count = 0;
  scanf("%d", &x);
  int modf, local_count;

  for (int i = 5; i > 0; i--) {
    if (x == 0) {
      break;
    }
    modf = x % i;
    local_count = (x - modf) / i;
    x -= (x - modf);
    count += local_count;
  }

  printf("%d", count);

  return EXIT_SUCCESS;
}