class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l,r,k=0,0,float("inf")
        curr_sum = 0
        #k is min len of subarray
        while r < len(nums):
            curr_sum += nums[r]
            
            while curr_sum >= target:
                if r - l+ 1 < k:
                    k = r - l + 1
                curr_sum -= nums[l]
                l += 1
            r+=1
            
        return k if k != float("inf") else 0        

        

        