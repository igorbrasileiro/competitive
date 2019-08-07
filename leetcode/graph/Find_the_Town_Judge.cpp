#include <bits/stdc++.h>

using namespace std;

struct person {
  int trustedBy = 0;
  bool canBeTownJudge = true;
};

int findJudge(int N, vector<vector<int>>& trust) {
  vector<person> peopleTrusts (N);
  for (int i = 0; i < N; i++) {
    person p;
    peopleTrusts[i] = p;
  }

  for (vector<int> const &trustPeople: trust) {
    peopleTrusts[trustPeople[1] - 1].trustedBy += 1;

    peopleTrusts[trustPeople[0] - 1].canBeTownJudge = false;
  }

  for (int i = 0; i < N; i++) {
    if (peopleTrusts[i].canBeTownJudge == 1 && peopleTrusts[i].trustedBy + 1 == N) {
      return i + 1; // index by 0
    }
  }

  return -1;
}

int main() {

  vector< vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
  int n = 4;

  cout << findJudge(n, trust);

  return 0;
}