function strStr(haystack, needle) {
  if (needle === "") {
    return 0;
  }

  const newStr = needle + "#" + haystack;
  const pi = Array(newStr.length);
  pi[0] = 0;
  let j = 0;

  for (let i = 1; i < newStr.length; i++) {
    j = pi[i - 1];
    while (j > 0 && newStr[i] !== newStr[j]) {
      j = pi[j - 1];
    }

    if (newStr[i] == newStr[j]) {
      j++;
    }

    pi[i] = j;

    // the default algoritm doesn't exists this part
    if (j === needle.length) {
      // i can be the len of newStr == len needle + 1 from # + len haystack
      // result is the actual `i` less the addition of needle and #
      // j - 1 because the match is inclusive = i - needle.length - 1 - (j - 1)
      return i - needle.length - j;
    }
  }

  return -1; // default return is pi
}
