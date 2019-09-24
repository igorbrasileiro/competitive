#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
      if (i <= r)
        z[i] = min (r - i + 1, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] - 1 > r)
        l = i, r = i + z[i] - 1;
  }
  return z;
}

int main() {
  string s;
  int n;

  vector<int> zf;

  scanf("%d\n\n", &n);
  for(int i = 0; i < n; i++) {
    getline(cin, s);
    scanf("\n");
    zf = z_function(s);
    int size = s.size();
    int output = size;
    for(int j = 0; j < size; j++) {
      int v = zf[j];
      if (v != 0 && size-j == v && size % j == 0 && v % j == 0) {
        output = j;
        break;
      }
    }
    if (i + 1 != n)  printf("%d\n\n", output);
    else printf("%d\n", output);

    zf.clear();
    s.clear();
  }

  return EXIT_SUCCESS;
}
