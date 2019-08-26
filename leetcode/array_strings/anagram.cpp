#include <bits/stdc++.h>
using namespace std;

bool verifyIsAnagram(string word1, string word2) {
  if (word1.size() != word2.size()) {
    return false;
  }

  // using array
  // int mymap[sizeof(char) * (1 << 9 - 1)]; // CHAR SIZE * BYTE DIM
  map<char, int> mymap;
  for(int i = 0; i < word1.size(); i++) {
    mymap[word1[i]] += 1;
  }

  bool result = true;
  for(int i = 0; i < word2.size(); i++) {
    if (mymap[word2[i]] == 0) {
      result = false;
      break;
    }
    mymap[word2[i]] -= 1;
  }

  return result;
}

// bool verifyIsAnagram(string word1, string word2) {
//   if (word1.size() != word2.size()) {
//     return false;
//   }

//   map<char, int> mymap;
//   for(int i = 0; i < word1.size(); i++) {
//     mymap[word1[i]] += 1;
//   }

//   bool result = true;
//   for(int i = 0; i < word2.size(); i++) {
//     if (mymap[word2[i]] == 0) {
//       result = false;
//       break;
//     }
//     mymap[word2[i]] -= 1;
//   }

//   return result;
// }

int main() {

  cout << verifyIsAnagram("abobora", "aabboor") << endl;


  return EXIT_SUCCESS;
}