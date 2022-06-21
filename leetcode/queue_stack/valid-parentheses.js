function stackTop(list) {
  return list[list.length - 1];
}

function isValid(s) {
  const stack = [];

  if (s.length % 2 === 1) {
    return false;
  }

  let top = "";

  for (let char of s) {
    if (char === "(" || char === "[" || char === "{") {
      stack.push(char);
    } else {
      top = stackTop(list);
      if (
        (char === ")" && top === "(") ||
        (char === "]" && top === "[") ||
        (char === "}" && top === "{")
      ) {
        stack.pop();
      } else {
        return false;
      }
    }
  }

  return stack.length === 0;
}
