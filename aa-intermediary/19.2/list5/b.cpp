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
  getline(cin, s);
  vector<int> pf = z_function(s);

  int maxi = *max_element(pf.begin(), pf.end());

  cout << maxi << endl;
  vector<int> counts(maxi + 1);

  int matches = 0;

  for(auto v: pf) {
    if(v != 0) {
      if(!counts[v]) matches++;
      counts[v]++;
    }
  }
  for(int i = maxi - 1; i >= 0; i--) {
    counts[i] += counts[i+1];
  }

  for(auto v: counts) {
    cout << 'C' << v << endl;
  }

  return EXIT_SUCCESS;
}
