class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:

        bitmask1 = 0

        for i in nums:
            bitmask1 ^= i

        bitmask2 = 0

        lsb = bitmask1 & (-bitmask1)

        for i in nums:
            if i & lsb != 0:
                bitmask2 ^= i

        return [bitmask2, bitmask2 ^ bitmask1]


        