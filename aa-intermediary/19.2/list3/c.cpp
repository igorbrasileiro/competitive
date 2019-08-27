#include <bits/stdc++.h>
using namespace std;

#define ll long long

// C - Inversion Count 

void compact(vector<int> &input, int n) {
  vector<int> aux(input);

  sort(aux.begin(), aux.end());

  for(int i = 0; i < n; i++) {
    input[i] = lower_bound(aux.begin(), aux.end(), input[i]) - aux.begin() + 1;
  }
}

ll getCount(vector<int> &BIT, int index) {
  ll sum = 0;
  while (index > 0) {
    sum += BIT[index];

    index -= index & (-index);
  }

  return sum;
}

void updateBIT(vector<int> &BIT, int n, int index, int val) {
  while(index <= n) {
    BIT[index] += 1;

    index += index & (-index);
  }
}

ll calcInversion(vector<int> &input, int n) {
  compact(input, n);
  vector<int> BIT (n + 1, 0); // bit[i] = sum of numbers that is less i;

  ll count = 0;
  for(int i = n - 1; i >= 0 ;i--)  {
    count += getCount(BIT, input[i] - 1);

    updateBIT(BIT, n, input[i], 1);
  }

  return count;
}

int main() {
  int n, n2, aux;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &n2);
    vector<int> input(n2);
    for(int j = 0; j < n2; j++) {
      scanf("%d", &input[j]);
    }
    cout << calcInversion(input, n2) << endl;
  }

  return EXIT_SUCCESS;
}