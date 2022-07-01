function isSorted(left, right) {
  return left <= right; // equal operator: because the left and mid can be equal
}
function binarySearch(nums, l, r, target) {
  if (l > r) {
    return -1;
  }

  const mid = l + Math.trunc((r - l) / 2);

  if (target === nums[mid]) {
    return mid;
  }

  if (target < nums[mid]) {
    // if is sorted from L to mid, target can loop if lower than L
    if (isSorted(nums[l], nums[mid]) && target < nums[l]) {
      return binarySearch(nums, mid + 1, r, target); // go right
    } else {
      return binarySearch(nums, l, mid - 1, target); // go left
    }
  } else {
    // if sorted from mid to R, target can loop if greater than R
    if (isSorted(nums[mid], nums[r]) && target > nums[r]) {
      return binarySearch(nums, l, mid - 1, target); // go left
    } else {
      return binarySearch(nums, mid + 1, r, target); // go right
    }
  }
}

function search(nums, target) {
  return binarySearch(nums, 0, nums.length - 1, target);
}
