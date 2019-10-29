#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, data_size, count, index;
  scanf("%d %d", &n, &data_size);
  vector<int> pendrives(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &pendrives[i]);
  }

  sort(pendrives.begin(), pendrives.end(), greater<int>());
  index = 0;
  count = 0;
  while(data_size > 0) {
    count++;
    data_size -= pendrives[index];
    index++;
  }

  printf("%d\n", count);

  return EXIT_SUCCESS;
}