function canJump(nums) {
  const maxJumpAtIdx = [nums[0]];
  for (let idx = 1; idx < nums.length; idx++) {
    maxJumpAtIdx[idx] = Math.max(maxJumpAtIdx[idx - 1] - 1, nums[idx]);
  }

  for (let idx = 0; idx < nums.length - 1; idx++) {
    if (maxJumpAtIdx[idx] == 0) {
      return false;
    }
  }

  return true;
}
