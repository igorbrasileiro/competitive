function maxSubArray(nums) {
  // mohit kumar > kadane algorithm
  let all_max = nums[0],
    current_max = nums[0];

  for (let x = 1; x < nums.length; x++) {
    current_max = Math.max(nums[x], current_max + nums[x]);
    all_max = Math.max(all_max, current_max);
  }

  return all_max;
}
