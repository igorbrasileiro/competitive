#include <bits/stdc++.h>
using namespace std;

int get_next_coin(int actual_coin) {
  int new_coin = 1;
  if (actual_coin == 100) {
    new_coin = 20;
  } else if (actual_coin == 20) {
    new_coin = 10;
  } else if (actual_coin == 10) {
    new_coin = 5;
  }

  return new_coin;
}

int main() { // poderia fazer PD mas acredito que rola TLE - 10^9
  int val;
  int coin = 100;
  scanf("%d", &val);
  int count = 0;

  while(val) {
    while (coin > val) {
      coin = get_next_coin(coin);
    }

    val -= coin;
    count++;
  }

  printf("%d\n", count);

  return EXIT_SUCCESS;
}