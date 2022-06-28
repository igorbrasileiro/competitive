function generateStringWithExtraChar(s) {
  const newStringArray = [];
  for (const char of s) {
    newStringArray.push("|");
    newStringArray.push(char);
  }
  newStringArray.push("|");

  return newStringArray.join("");
}

function getLeftIndex(center, radius) {
  return center - (radius + 1);
}

function getRightIndex(center, radius) {
  return center + (radius + 1);
}

function isIndexInsideStr(center, radius, strLength) {
  return (
    getLeftIndex(center, radius) >= 0 &&
    getRightIndex(center, radius) < strLength
  );
}

// Algorrightm https://en.wikipedia.org/wiki/Longest_palindromic_substring#Slow_algorithm
function longestPalindrome(s) {
  const newStrWithChar = generateStringWithExtraChar(s);
  let center = 0,
    radius = 0,
    highestRadius = 0,
    highestCenter;

  while (center < newStrWithChar.length) {
    radius = 0;
    while (
      isIndexInsideStr(center, radius, newStrWithChar.length) &&
      str[getLeftIndex(center, radius)] === str[getRightIndex(center, radius)]
    ) {
      radius += 1;
    }

    if (radius > highestRadius) {
      highestRadius = radius;
      highestCenter = center;
    }

    center += 1;
  }

  const resultArray = [];

  // generate the output string
  for (
    let idx = highestCenter - highestRadius;
    idx <= highestCenter + highestRadius;
    idx++
  ) {
    if (newStrWithChar[idx] !== "|") {
      resultArray.push(newStrWithChar[idx]);
    }
  }

  return resultArray.join("");
}
