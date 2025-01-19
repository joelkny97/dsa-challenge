class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        res = []
        #sort using built-in
        nums.sort()

        

        for l in range(len(nums)):
            if l > 0 and nums[l] == nums[l-1]:
                continue
            r,t=l+1,len(nums)-1



            while r<t:
                tot = nums[l]+nums[r]+nums[t]
            
                if tot > 0:
                    t-=1
                elif tot < 0:
                    r+=1
                else:
                    res.append([nums[l], nums[r], nums[t]])
                    r+=1
                    while nums[r] == nums[r-1] and r<t:
                        r+=1

        return res

                        



        
        