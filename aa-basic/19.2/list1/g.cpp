#include <bits/stdc++.h>
using namespace std;

int main() {

  int l1, l2, ml1 = INT_MAX, ml2 = INT_MAX, v;
  scanf("%d %d", &l1, &l2);
  vector<int> l1s(l1), l2s(l2);

  for (int i = 0; i < l1; i++) {
    scanf("%d", &l1s[i]);
    ml1 = min(ml1, l1s[i]);
  }

  for (int i = 0; i < l2; i++) {
    scanf("%d", &l2s[i]);
    ml2 = min(ml2, l2s[i]);
  }


  int min_both = 10;
  for (int v1: l1s) {
    for (int v2: l2s) {
      if (v1 == v2) {
        min_both = min(v1, min_both);
      }
    }
  }

  if (min_both != 10) {
    printf("%d\n", min_both);
  } else {
    if (ml1 < ml2) {
      printf("%d%d\n", ml1, ml2);
    } else {
      printf("%d%d\n", ml2, ml1);
    }
  }

  return EXIT_SUCCESS;
}