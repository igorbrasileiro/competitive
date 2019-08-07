#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  int minValue, maxValue;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < minValue) {
      minValue = nums[i];
    }

    if (nums[i] > maxValue) {
      maxValue = nums[i];
    }
  }
    if (minValue > 0) {
        minValue = 0;
    }
  vector<int> arrayCount(abs(minValue) + 1 + maxValue);

  for (int i = 0; i < nums.size(); i++) {
    arrayCount[nums[i] + abs(minValue)] += 1;
  }

  // for (auto const &c: arrayCount) {
  //   cout << c << ", ";
  // } cout << endl;

  vector<int> values(2);

  for (int j = 0; j < arrayCount.size(); j++) {
    if (arrayCount[j] > 0) {
      arrayCount[j] += -1;
      int selectedValue = j + minValue;
      int complement = target - selectedValue;
      if (minValue <= complement && complement + abs(minValue) < arrayCount.size()
            && arrayCount[complement + abs(minValue)] > 0) {
              // cout << "entrie" << endl;
              values[0] = selectedValue;
              values[1] = complement;
              break;
      }
    }
  }

  // get index of selected values
  vector<int> result = {-1, -1};
  for (int i = 0; i < nums.size(); i++) {
    if (values[0] == nums[i] && result[0] < 0) {
      result[0] = i;
    } else if (values[1] == nums[i] && result[1] < 0) {
      result[1] = i;
    }
  }

  // case index is not crescent
  if (result[0] > result[1]) {
    int aux = result[0];
    result[0] = result[1];
    result[1] = aux;
  }
  
  cout << result[0] << " " << result[1] << endl;

  return result;
}

int main() {
  vector<int> nums = {-2, -3, -4, 7, 0};
  twoSum(nums, 4);

  return 0;
}