function removeElement(nums, val) {
  let i = 0,
    j = 0,
    count = 0;

  while (j < nums.length) {
    while (j < nums.length && nums[j] === val) {
      j++;
      count++;
    }
    nums[i] = nums[Math.min(j, nums.length - 1)];
    i++;
    j++;
  }

  return nums.length - count;
}
