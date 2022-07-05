function merge(intervals) {
  intervals.sort((intervalA, intervalB) => intervalA[0] - intervalB[0]);

  const result = [intervals[0]];
  let intervalEnd = intervals[0][1];
  let idx = 1;

  while (idx < intervals.length) {
    const interval = intervals[idx];

    if (intervalEnd >= interval[0]) {
      if (intervalEnd < interval[1]) {
        intervalEnd = interval[1];
        result[result.length - 1][1] = intervalEnd;
      }
    } else {
      intervalEnd = interval[1];
      result.push(interval);
    }

    idx += 1;
  }

  return result;
}
