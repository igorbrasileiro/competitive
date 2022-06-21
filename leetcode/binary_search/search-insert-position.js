function searchInsert(nums, target) {
  return binarySearch(nums, target, 0, nums.length - 1);
}

function binarySearch(nums, target, left, right) {
  // !( left > right) === left <= right
  let middle = 0;
  while (left <= right) {
    middle = left + Math.floor((right - left) / 2);

    if (nums[middle] === target) {
      return middle;
    } else {
      if (target < nums[middle]) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
  }

  return left; // default return -1
}

// function binarySearch(nums: number[], target: number, left: number, right: number) {
//   if (left > right) {
//     return left // default return -1
//   }

//   const middle = left + Math.floor((right - left) / 2)

//   if (nums[middle] === target) {
//     return middle
//   } else {
//     if (target < nums[middle]) {
//       return binarySearch(nums, target, left, middle - 1)
//     } else {
//       return binarySearch(nums, target, middle + 1, right)
//     }
//   }
// };
