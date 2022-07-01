function combinationSum2(candidates, target, result, sum, sequence, start) {
  if (start === candidates.length) {
    return;
  }

  for (let i = start; i < candidates.length; i++) {
    if (sum + candidates[i] > target) {
      continue;
    } else if (sum + candidates[i] === target) {
      const entry = Array.from(sequence);
      entry.push(candidates[i]);
      result.push(entry);
      return;
    }

    sequence.push(candidates[i]);
    combinationSum2(
      candidates,
      target,
      result,
      sum + candidates[i],
      sequence,
      i
    );
    sequence.pop();
  }
}

function combinationSum(candidates, target) {
  const result = [];
  candidates.sort((a, b) => a - b)
  combinationSum2(candidates, target, result, 0, [], 0);
  return result;
}
