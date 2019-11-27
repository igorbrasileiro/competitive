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

  ll n;
  scanf("%lld", &n);

  ll res = (fast_pow(4, n) + fast_pow(2, n - 1)) / 2; // need modular division
  printf("%lld", res);

  return EXIT_SUCCESS;
}