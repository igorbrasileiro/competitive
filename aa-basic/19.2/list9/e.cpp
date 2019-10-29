#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<long> h(n), x(n);

  for (int i = 0; i < n; i++) {
    scanf("%ld %ld\n", &x[i], &h[i]);
  }

  long res = (n == 1) ? 1 : 2;

  for (int i = 1; i < n - 1; i++) {
    if (x[i] - x[i - 1] > h[i]) {
      res++;
    } else if (x[i + 1] - x[i] > h[i]) {
      res++;
      x[i] += h[i];
    }
  }

  printf("%ld\n", res);

  return EXIT_SUCCESS;
}