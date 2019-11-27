#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, v;
  scanf("%d", &n);

  unordered_set<int> distinct_values;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v);
    if (v > 0) {
      distinct_values.insert(v);
    }
  }

  v = distinct_values.size();
  printf("%d", v);

  return EXIT_SUCCESS;
}