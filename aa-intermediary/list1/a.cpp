#include <bits/stdc++.h>

using namespace std;

// A - Zero Quantity Maximization - cf
int main() {

  int n, a, any_d_count;
  long double b;
  vector<int> a_elements;
  map<long double, int> d_occurencies;

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    a_elements.push_back(a);
  }

  any_d_count = 0;

  for(int i = 0; i < n; i++) {
    scanf("%LF", &b);
    if (a_elements[i] != 0) {
      d_occurencies[-b/a_elements[i]]++;
    } else if (b == 0) {
      any_d_count++;
    }
  }

  double result = 0;
  for(map<long double, int>::iterator it = d_occurencies.begin(); it != d_occurencies.end(); ++it) {
    if (it->second > result) {
      result = it->second;
    }
  }

  cout << result+any_d_count << endl;

  return 0;
}