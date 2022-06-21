function removeDuplicates(nums){
  if (nums.length <= 1) { return 1 }
  let i = 0, j = 1, count = 0
  
  while (j < nums.length) {
    while (nums[i] === nums[j] && j < nums.length) {
      j++
      count++
    }
    
    nums[i + 1] = nums[Math.min(j, nums.length - 1)]
    i++;
    j++;
  }
  
  return nums.length - count
};
