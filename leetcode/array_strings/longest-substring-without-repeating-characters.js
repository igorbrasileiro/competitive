function lengthOfLongestSubstring(s) {
  let letterPositionMap = {}
  let longSubStrSize = 0
  let start = 0, end = 0
  
  while (end < s.length) {
    if (letterPositionMap[s[end]] !== undefined) {
      const duplicatedIndex = letterPositionMap[s[end]]
      longSubStrSize = Math.max(longSubStrSize, end - start)
      
      // clean entries from start to duplicatedIndex inclusive
      for (let idx = start; idx <= duplicatedIndex; idx++) {
        letterPositionMap[s[idx]] = undefined
      }

      start = duplicatedIndex + 1
    }
    
    letterPositionMap[s[end]] = end
    end += 1
  }
  
  longSubStrSize = Math.max(longSubStrSize, end - start)
  
  return longSubStrSize
};