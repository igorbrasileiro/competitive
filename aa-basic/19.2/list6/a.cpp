#include <bits/stdc++.h>
using namespace std;



int main() {
  int base, target, count;
  scanf("%d %d", &base, &target);
  count = 0;
    while(base < target) {
      // printf("target: %d - count: %d\n", target, count);
      if (target % 2 == 0) {
        target /= 2;
      } else {
        target++;
      }
      count++;
    }
  count += (base - target);
  printf("%d\n", count);
  return EXIT_SUCCESS;
}
