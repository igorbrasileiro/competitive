#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

int main() {
  int myInts[] = {2,1,2,5,3,2};
  vector<int> A (myInts, myInts + sizeof(myInts) / sizeof(int));
  // begin here
  map<int, int> myMap;
  int result = -1;
  for (int const &value: A) {
    if (myMap.find(value) == myMap.end()) {
      myMap[value] = 1;
    } else {
      result = value;
      break;
    }
  }

  // return result;
  cout << result << endl;

  return 0;
}