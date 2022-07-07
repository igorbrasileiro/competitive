function insert(intervals, newInterval) {
  const result = [];
  let tempInterval = newInterval;

  /** destructive thinking / idea of insertion sort
   * if tempInterval[0] is greater than interval[1], add interval. Temp is greater
   * if tempInterval[1] is smaller than interval[0], add tempInterval, and set interval as tempInterval
   * else it's an overlap, tempInterval = [min(tempInterval, interval), max(tempInterval, interval)]
   * After the loop, tempInterval will be the last interval
   */
  for (const interval of intervals) {
    if (interval[1] < tempInterval[0]) {
      result.push(interval);
    } else if (tempInterval[1] < interval[0]) {
      result.push(tempInterval);
      tempInterval = interval;
    } else {
      // overlap
      tempInterval[0] = Math.min(tempInterval[0], interval[0]);
      tempInterval[1] = Math.max(tempInterval[1], interval[1]);
    }
  }

  result.push(tempInterval);

  return result;
}
