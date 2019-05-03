#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/to-lower-case/

int main() {
  string str = "AbCdE";

  for (char &c: str) {
    c = tolower(c);
  }

  // return str; // question answer
  return 0;
}
