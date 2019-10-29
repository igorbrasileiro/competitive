#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, neg, zero;
  scanf("%d", &n);
  vector<int> values(n);
  neg = 0; zero = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &values[i]);
    if (values[i] < 0) {
      neg++;
    } else if (values[i] == 0) {
      zero++;
    }
  }

  long long result = 0;
  for (int i = 0; i < n; i++) {
    if (values[i] != 0) {
      result += abs((int)abs(values[i]) - 1);
    }
  }

  if (neg % 2 == 0) {
  result += zero;
  } else {
    if (zero) {
      result += zero;
    } else {
      result += 2;
    }
  }

  printf("%lld\n", result);

  return EXIT_SUCCESS;
}