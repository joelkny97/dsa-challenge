class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        prod = 1
        max_prod = float('-inf')

        for i in nums:
            prod*=i
            max_prod = max(prod, max_prod)

            if prod==0:
                prod=1
        
        prod = 1

        for i in nums[::-1]:
            prod*=i
            max_prod = max(prod, max_prod)

            if prod==0:
                prod=1

        return max_prod

        


        