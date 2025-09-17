class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        res = maj = 0

        for n in nums:
            if maj == 0:
                res = n

            maj +=1 if n == res else -1

        return res
        