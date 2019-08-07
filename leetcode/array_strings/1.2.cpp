#include <bits/stdc++.h>

using namespace std;

// Given two strings, write a method to decide 
// if one is a permutation of the other.
inline int getCharPosition(char c) {
  return c - 'a';
}

inline void checkIsPermutation(string &w1, string &w2) {
  string result = "yes";
  vector<int> w1_count(26), w2_count(26);
  for (int i = 0; i < w1.size(); i++) {
    w1_count[getCharPosition(w1[i])] += 1;
    w2_count[getCharPosition(w2[i])] += 1;
  }

  for (int i = 0; i < w1.size(); i++) {
    if (w1_count[i] != w2_count[i]) {
      result = "no";
    }
  }

  cout << result << endl;
}

int main() {
  int qtd;
  scanf("%d", &qtd);
  string w1, w2;

  for (int i = 0; i < qtd; i++) {
    getline(cin, w1, ' ');
    getline(cin, w2, '\n');
    
    checkIsPermutation(w1, w2);
  }

  return 0;
}