#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/unique-morse-code-words/

int main() {
  // given by question
  string myStrings[] = {"gin", "zen", "gig", "msg"};
  vector<string> words (myStrings, myStrings + sizeof(myStrings) / sizeof(string));

  // answer
  string morseCodes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  char alphabet[] = {'a',	'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  map<char, string> alphabetMap;

  for(int i = 0; i <= 25; i++) { // has 26 characters
    alphabetMap[alphabet[i]] = morseCodes[i];
  }

  set<string> result;
  string auxMorse = "";
  for (string const &str: words) {
    for (char const &c: str) {
      auxMorse += alphabetMap.find(c) -> second;
    }
    result.insert(auxMorse);
    auxMorse = "";
  }

  return result.size();
  // cout << result.size() << endl;

  return 0;
}