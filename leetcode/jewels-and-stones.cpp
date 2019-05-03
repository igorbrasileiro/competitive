#include<bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/jewels-and-stones/submissions/

int main()
{
    string J = "aA";
    string S = "bbBBbaaA";
    map<char, int> map;

   for (char const &c: J) {
        map[c] = 1;
    }

    int result = 0;
    for (char const &c: S) {
        if (map.find(c) != map.end()) {
            result += 1;
        }
    }

    cout << result << endl;
    return 0;
}