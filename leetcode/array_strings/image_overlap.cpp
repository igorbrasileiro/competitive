#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
      vector<pair<int,int>> cordsA, cordsB;
      for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
          if (A[i][j] == 1) {
            cordsA.push_back(make_pair(i, j));
          }
          if (B[i][j] == 1) {
            cordsB.push_back(make_pair(i, j));
          }
        }
      }
      
      map<pair<int,int>, int> difsCords;
      int maxOverlap = 0;
      for(const pair<int,int> &pa: cordsA) {
        for(const pair<int,int> &pb: cordsB) {
          pair<int,int> delta = make_pair(pa.first-pb.first, pa.second - pb.second);
          difsCords[delta] += 1;
          maxOverlap = max(difsCords[delta], maxOverlap);
        }
      }
      
      return maxOverlap;
    }
};

int main() {
  return EXIT_SUCCESS;
}