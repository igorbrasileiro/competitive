#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> degrees(n);
  for (int i = 0; i < n; i++) scanf("%d", &degrees[i]);

  // generate all combinations, for each n-ith number can be rotated clockwise our counter...
  // n = 1 ; +val1 or -val1
  // n = 2; +val1+val2 +val1-val2  -val1+val2 -val1-val2
  // do this for each degrees;
  // use bit from any tree_combination;
  int tree_combination = 1 << n; 
  int sum = 0;
  bool flag = false;

  for (int j = 0; j < tree_combination; j++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      if ((1 << i) & j) {
        sum += degrees[i];
      } else {
        sum -= degrees[i];
      }
    }
    

    if (sum % 360 == 0) {
      flag = true;
      break;
    }
  }

  if (flag) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  
  return EXIT_SUCCESS;
}