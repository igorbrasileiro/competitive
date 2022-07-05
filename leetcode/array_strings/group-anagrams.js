function sortString(str) {
  return str
    .split("")
    .sort((letterA, letterB) => letterA.localeCompare(letterB))
    .join("");
}

function mapUpdateOrInsert(map, key, value) {
  if (!map.get(key)) {
    map.set(key, [])
  }

  map.get(key).push(value)
}

function groupAnagrams(strs) {
  const mapAnagramStrs = new Map([])

  strs.forEach(str => {
    mapUpdateOrInsert(mapAnagramStrs, sortString(str), str)
  });

  const result = []
  for (const anagramList of mapAnagramStrs.values()) {
    result.push(anagramList)
  }

  return result
}

console.log(groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
