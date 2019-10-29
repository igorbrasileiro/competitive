#include <bits/stdc++.h>
using namespace std;

vector<bool> dec_to_binary(int val) {
  vector<bool> binary(20, false);
  int i = 0;
  while(val != 0) {
    binary[i] = val % 2 == 0 ? false : true;
    val /= 2;
    i++;
  }

  return binary;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  vector< vector<bool>> armys(m);
  int aux;

  for(int i = 0; i < m; i++) {
    scanf("%d", &aux);
    armys[i] = dec_to_binary(aux);
  }

  scanf("%d", &aux);
  vector<bool> freedor = dec_to_binary(aux);

  int count = 0, result = 0;
  for(auto army: armys) {
    for (int i = 0; i < 20; i++) {
      if (army[i] != freedor[i]) {
        count++;
      }
    }
    if(count <= k) result++;
    count = 0;
  }

  cout << result << endl;

  return EXIT_SUCCESS;
}