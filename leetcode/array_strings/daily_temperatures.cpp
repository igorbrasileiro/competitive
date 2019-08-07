#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &T) {
  vector<stack<int>> matrix(71);
  for (int i = 0; i < matrix.size(); i++) {
    stack<int> newStack;
    matrix[i] = newStack;
  }

  int aux = 0;
  vector<int> result (T.size());
  for (int i = T.size() - 1; i >= 0; i--) {
    matrix[T[i] - 30].push(i);
    aux = T.size();
    // cout << i << " " << aux << endl;
    // pegar proxima temperatura maior, que tem menor distancia até j;
    for (int j = T[i] + 1; j <= 100; j++) {
      // cout << "j: " << j << endl;
      if (matrix[j- 30].size() > 0 && matrix[j - 30].top() < aux) {
        // cout << "entrei: " << T[i] << " " << j << endl;
        aux = matrix[j - 30].top();
      }
    }
    // cout << T[i] << " " << aux << " " << i << endl;
    if (aux == T.size()) {
      result[i] = 0;
    } else {
      result[i] = aux - i;
    }
  }

  // for (auto const &c: result) {
  //   cout << c << " ";
  // }

  return result;
}

int main() {
  vector<int> x = {73,74,75,71,69,72,76,73};
  dailyTemperatures(x);
  return 0;
}