#include <bits/stdc++.h>

using namespace std;
#define ll long long;

int maxSumAfterPartitioning(vector<int>& A, int K) {
  int lenPd = A.size() + 1;
  vector<int> pd(lenPd, 0);

  int auxNum = INT_MIN;
  for (int i = 1; i < lenPd; i++) {
    auxNum = INT_MIN;
    for (int j = 1; j < min(i, K) + 1; j++) {
      auxNum = max(auxNum, A[i - j]); // get max of A[i]...A[i-j]
      pd[i] = max(pd[i], pd[i - j] + auxNum * j); // last max of (actual sum, last max sum + auxNum * j, where j is the window range
    }
  }

  return pd[pd.size() - 1];
}

int main() {
  vector<int> list = {1,4,1,5,7,3,6,1,9,9,3};
  int k = 4;

  cout << maxSumAfterPartitioning(list, k) << endl;

  return EXIT_SUCCESS;
}
