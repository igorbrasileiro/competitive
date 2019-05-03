#include <bits/stdc++.h>

using namespace std;

// Balanced Team - cf

int main() {
  vector<int> inputs;
  int n, aux;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &aux);
    inputs.push_back(aux);
  }

  sort(inputs.begin(), inputs.end());

  int result = 0;
  aux = 0;
  for (int i = 0; i < n; i++) {
    while(aux < n && inputs[aux] - inputs[i] <= 5) { // run till limit input[i] + 5 = input[j]
      aux++;
      result = max(result, aux-i);
    }
  }

  cout << result << endl;

  return 0;
}