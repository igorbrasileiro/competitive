#include <bits/stdc++.h>

using namespace std;

// Game with string - cf
int main() {
  string s;
  cin >> s;

  stack<int> stack;
  int i, count;// unused aux index
  
  while (i < s.size()) { // 0 1
    if (!stack.empty()) {
      if (stack.top() == s[i]) {
        stack.pop();
        count++;
      } else {
        stack.push(s[i]);
      }
    } else {
      stack.push(s[i]);
    }
    i++;
  }

  if (count % 2 == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}