#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/unique-email-addresses/

int main() {
  string myEmails[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
  vector<string> emails (myEmails, myEmails + sizeof(myEmails) / sizeof(string));
  // code start here;
  bool afterPlus = false;
  bool afterAt =  false;
  string aux;
  map<string, int> validEmails;
  vector<string> result;

  for (string const &email: emails) {
    for (char const &c: email) {
      if (c == '+') {
        afterPlus = true;
      }

      if (c == '@') {
        afterAt = true;
      }

      if (!afterPlus && c != '.') {
        aux += c;
      } else if (afterAt) {
        aux += c;
      }
    }
    validEmails[aux] = 1;

    afterAt = false;
    afterPlus = false;
    aux = "";
  }

  return validEmails.size();
}