#include <bits/stdc++.h>
using namespace std;

//kmp prefix-function code by cp-algorithm
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


// end of prefix-function

int main() {
  string s;
  getline(cin, s);
  vector<int> pf = prefix_function(s);
  bool hasFound = false;
  int v;
  int size = pf.size();
  

  for(auto v: pf) printf("%d, ", v);
  for(int i = size - 1; i >= 0; i--) {} 

  if (!hasFound) printf("Just a legend");
  
  return EXIT_SUCCESS;
}
