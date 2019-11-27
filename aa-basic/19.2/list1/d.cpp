#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
  while(l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

int main() {

  string s;
  getline(cin, s);

  int res = 0;
  for(int i = 0; i < s.size(); i++) {
    for(int j = i + 1; j < s.size(); j++) {
      if (!isPalindrome(s, i, j)) {
        res = max(res, j - i + 1);
      }
    }
  }

  printf("%d\n", res);

  return EXIT_SUCCESS;
}