#include <bits/stdc++.h>
using namespace std;

vector<int> KMP(string s){
  vector<int> pf(s.length() + 1);
  int now;

  pf[0] = now = -1;

  for(int i = 1; i < s.length(); i++) {
    while(now != -1 && s[i]!=s[now+1]) {
      now = pf[now];
    }

    if(s[i] == s[now+1]) {
      pf[i] = ++now;
    } else {
      pf[i]= -1;
    }
  }

  return pf;
}


// end of prefix-function

int main() {
  string s;
  getline(cin, s);
  int size = s.length();
  vector<int> pf = KMP(s);

  int maxi = pf[size - 1];
  int found = pf[maxi];

  if(maxi == -1) {
    found = -1;
  }
  
  for (int i = 0; i < size - 1; i++) {
    if(pf[i] == maxi) {
      found = maxi;
    }
  }

  if (found == -1) {
    printf("Just a legend\n");
  } else {
    cout << s.substr(0, found+1) << endl;
  }
  
  return EXIT_SUCCESS;
}
