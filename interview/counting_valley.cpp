#include <bits/stdc++.h>
using namespace std;

int countingValleys(int n, string s) {
  int aux = 0;
  int count_val = 0;

  for(int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      aux++;
    } else {
      if (aux == 0) {
        count_val++;
      }
      aux--;
    }
  }

  return count_val;
}


int main() {
  int n;
  char c;
  scanf("%d\n", &n);
  string s;
  for (int i = 0; i < n; i++) {
    scanf("%c", &c);
    s.push_back(c);
  }

  cout << s << endl;
  cout << countingValleys(n, s);

  return EXIT_SUCCESS;
}