class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        
        if not nums or len(nums) == 0:
            return False

        
        low = 0
        high = len(nums)-1

        while(low<=high):

            mid = low +(high-low)//2

            if nums[mid] == target:
                return True
            # to deal with duplicates just move towards the center
            if nums[low] == nums[mid] and nums[mid] == nums[high]:
                low+=1
                high-=1

            elif nums[low] <= nums[mid]:
                # left side is sorted
                if nums[low] <= target and nums[mid] > target:
                    high = mid-1
                else:
                    low = mid + 1
            else:
                # right side is sorted
                if nums[mid] < target and target <= nums[high]:
                    low = mid+1
                else:
                    high = mid-1

            
        return False
