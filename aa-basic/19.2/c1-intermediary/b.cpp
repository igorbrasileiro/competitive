#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  int pos_one, pos_n;
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &values[i]);
    if (values[i] == 1) {
      pos_one = i + 1;
    } else if (values[i] == n) {
      pos_n = i + 1;
    }
  }

  int result = max(max(pos_n - 1, n - pos_n), max(pos_one - 1, n - pos_one));
  printf("%d\n", result);

  return EXIT_SUCCESS;
}