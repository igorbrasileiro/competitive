#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  scanf("%d", &n);
  vector<int> cities (n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &cities[i]);
  }

  int minl, maxl;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      minl = abs(cities[i+1] - cities[i]);
    } else if (i == n - 1) {
      minl = abs(cities[i - 1] - cities[i]);
    } else {
      minl = min(abs(cities[max(0, i - 1)] - cities[i]), abs(cities[min(n - 1, i + 1)] - cities[i]));
    }
    maxl = max(abs(cities[0] - cities[i]), abs(cities[n - 1] - cities[i]));
    printf("%d %d\n", minl, maxl);
  }

  return EXIT_SUCCESS;
}