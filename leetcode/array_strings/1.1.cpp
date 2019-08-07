#include <bits/stdc++.h>

using namespace std;

// Implement an algorithm to determine if a string has all 
// unique characters. What if you cannot use additional data
// structures
int main()
{
  string word;
  getline(cin, word);

  string isUnique = "yes";
  char c;
  c = word[0];

  for (int i = 1; i < word.size(); i++) {
    if (c != word[i]) {
      isUnique = "no";
    }
  }

  cout << isUnique << endl;

  return 0;
}