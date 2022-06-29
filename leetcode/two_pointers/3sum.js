function threeSum(nums) {
  const result = [];
  nums.sort((a, b) => a - b);

  // i, j = i + 1, k = nums.length - 1, that's the motive '-2'
  for (let i = 0; i + 2 < nums.length; i++) {
    // skip duplicates from left [-1, -1, 0, 1]
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    let j = i + 1;
    let k = nums.length - 1;
    while (j < k) {
      let sum = nums[i] + nums[j] + nums[k];
      if (sum == 0) {
        result.push([nums[i], nums[j], nums[k]]);

        k--;

        // skip duplicates from left [-1, 0, 1, 1]
        while (j < k && nums[k] == nums[k + 1]) {
          k--;
        }
      } else if (sum > 0) {
        // need decrease
        k--;
      } else {
        // need increase
        j++;
      }
    }
  }
  return result;
}
