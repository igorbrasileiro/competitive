#include <bits/stdc++.h>
using namespace std;

inline bool verify_is_valid_instructions(char COMMANDS[], int l, int r) {
  int x = 0; int y = 0;
  for (int h = l; h <= r; h++) {
    if (COMMANDS[h] == 'L') {
      x -= 1;
    } else if (COMMANDS[h] == 'R') {
      x += 1;
    } else if (COMMANDS[h] == 'U') {
      y -= 1;
    } else {
      y += 1;
    }
  }

  return x == 0 && y == 0;
}

int main() {
  int n;
  char COMANDS[200];
  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    scanf("%c", &COMANDS[i]);
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (verify_is_valid_instructions(COMANDS,i,j)) {
        count++;
      }
    }
  }

  printf("%d\n", count);

  return EXIT_SUCCESS;
}