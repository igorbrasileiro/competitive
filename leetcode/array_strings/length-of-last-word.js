function lengthOfLastWord(s) {
  let count = 0,
    i = s.length - 1;

  while (i >= 0) {
    while (s[i] != " " && i >= 0) {
      count += 1;
      i -= 1;
    }

    if (count > 0) {
      break;
    }

    i -= 1;
  }

  return count;
}
