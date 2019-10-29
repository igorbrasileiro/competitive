#include <bits/stdc++.h>
using namespace std;

#define ll long long

int MOD = 1000000007;

ll fast_pow(ll base, ll exp) {
  ll result = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = ((result % MOD) * (base % MOD)) % MOD;
    }
    // ODD division trncate
    exp = exp >> 1;
    base = ((base % MOD) * (base % MOD)) % MOD;
    // printf("%d -- %d\n", base, result);
  }

  return result;
}

int main() {
  int n, base, exp;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &base, &exp);
    cout << fast_pow(base, exp) << endl;
  }

  return EXIT_SUCCESS;
}