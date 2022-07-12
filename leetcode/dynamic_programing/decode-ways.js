/**
 * previous means i - 1 position, current means i.
 * if current >= 1 and <= 9, dp[i] += dp[i - 1] (or the previous). Example with 5 nums: ****1, the result(dp[i]) is the same of **** nums
 * if previous >= 10 and <= 26, dp[i] += dp[i - 2]. Example considering the previous with 5 nums: ***21, is adding the result from *** nums
 */

function numDecodings(s) {
  let waysToDecode = new Array(s.length + 1).fill(0);
  waysToDecode[0] = 1;

  for (let i = 1; i <= s.length; i += 1) {
    const twoChar = Number(s.slice(i - 2, i));
    const oneChar = Number(s.slice(i - 1, i));

    if (oneChar > 0) {
      waysToDecode[i] = waysToDecode[i - 1];
    }

    if (twoChar >= 10 && twoChar <= 26) {
      waysToDecode[i] += waysToDecode[i - 2];
    }
  }

  return waysToDecode[s.length];
}
