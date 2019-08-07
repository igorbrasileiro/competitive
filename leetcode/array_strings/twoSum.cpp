#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> table;
  for (int i = 0; i < nums.size(); i++) {
    table[nums[i]] += 1;
  }

  int value, diff;
  for (map<int, int>::iterator it = table.begin(); it != table.end(); ++it) {
    if (it->second > 0) {
      value = it->first;
      table[value] -= 1;
      diff = target - value;
      map<int, int>::iterator snd_it = table.find(diff);
      if (snd_it != table.end() && snd_it->second > 0) {
        // cout << "r" << value << " " << snd_it->first << endl;
        break;
      }
    }
  }
  
  vector<int> result = {-1,-1};
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == value && result[0] < 0) {
      result[0] = i;
    } else if (nums[i] == diff && result[1] < 0) {
      result[1] = i;
    }
  }

  if (result[0] > result[1]) {
    int aux = result[0];
    result[0] = result[1];
    result[1] = aux;
  }

  return result;
}

// [-4, -3, -3, 0, 2], target = -6; minValue = -4 
// ==> [(1 -4), (2, -3), (0, -2), (0, -1), (1, 0), (0, 1), (1,2)];
// i = 1; diff = -6 - (1 - 4) => -6 - (-3) = -3 + abs(minValue) = 1


int main() {
  int qtd, target;
  scanf("%d", &qtd);

  for (int i = 0; i < qtd; i++) {
    vector<int> nums(4);
    for (int j = 0; j < 4; j++) {
      scanf("%d", &nums[j]);
    }
    scanf("%d", &target);

    vector<int> result;
    result = twoSum(nums, target);

    for(auto const &c: result) {
      cout << c << " ";
    }
    cout << endl;
  }


  return 0;
}