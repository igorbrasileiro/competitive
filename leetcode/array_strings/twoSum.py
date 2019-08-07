class Solution(object):
    def twoSum(self, nums, target):
        maxValue = max(nums)
        minValue = min(nums)
        if minValue > 0:
          minValue = 0

        arrayCount = [0] * (abs(minValue) + abs(maxValue) + 1)

        for x in nums:
          arrayCount[x + abs(minValue)] += 1

        # print str(arrayCount)  
        values = [0,0]
        
        for i in xrange(len(arrayCount)):
          if (arrayCount[i] > 0):
            arrayCount[i] += -1
            selectedValue = i + minValue
            complement = target - selectedValue
            print complement
            if (minValue <= complement and complement <= maxValue and arrayCount[complement + abs(minValue)] > 0):
              values[0] = selectedValue
              values[1] = complement
              break

        # print 'values', values[0], values[1]

        result = [-1, -1]
        for j in xrange(len(nums)):
          if (values[0] == nums[j] and result[0] < 0):
            result[0] = j
          elif(values[1] == nums[j] and result[1] < 0):
            result[1] = j

        if (result[0] > result[1]):
          aux = result[0]
          result[0] = result[1]
          result[1] = aux

        return result
              