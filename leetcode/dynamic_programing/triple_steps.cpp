#include <bits/stdc++.h>
using namespace std;

int calc_steps(int n, vector<int> &prev) {
  prev.push_back(prev[n - 1] + prev[n - 2] + prev[n - 3]);
}

int calc_steps(int n) {
  vector<int> prev = {0, 1, 2, 4};
  if (n <= 3) {
    return prev[n];
  }

  for (int i = 4; i <= n; i++) {
    calc_steps(i, prev); // can optimize removing array and use a, b, c and aux for new value;
  }

  return prev[n];
}

int main() {
  cout << calc_steps(10) << endl;

  return EXIT_SUCCESS;
}