#include <bits/stdc++.h>

using namespace std;

// Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end
// to hold the additional characters, and that you are given the
// "true" length of the string. (Note: If implementing in Java,
// please use a character array so that you can perform this operation in place.)

void urlify(string &phrase, int size) {
  string result = "";
  for (int i = 0; i <= size; i++) {
    if (phrase[i] == ' ') {
      result.append("%20");
    } else {
      result += phrase[i];
    }
  }

  cout << result.c_str();
}

int main() {
  int qtd, size;
  string phrase = "";
  scanf("%d", &qtd);

  for (int i = 0; i < qtd; i++) {
    getline(cin, phrase, ',');
    scanf("%d", &size);
    urlify(phrase, size);
  }

  return 0;
}