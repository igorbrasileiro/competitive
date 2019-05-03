#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/sort-array-by-parity/

int main() {
  // given 
  int given[] = {3,1,2,4};
  vector<int> A (given, given + sizeof(given) / sizeof(int));
  // answer
  vector<int> odd;
  vector<int> even;

  for (int const &value: A) {
    if (value % 2 == 0) {
      even.push_back(value);
    } else {
      odd.push_back(value);
    }
  }

  sort(even.begin(), even.begin()+even.size());
  sort(odd.begin(), odd.begin()+odd.size());

  vector<int> result (even);
  for (int const &v: odd) {
    result.push_back(v);
  }

  // return result;

  for (int const &v: result) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}