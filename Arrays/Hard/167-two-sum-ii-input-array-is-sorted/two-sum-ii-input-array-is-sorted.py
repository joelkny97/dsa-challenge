class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        idx1, idx2 = 0,len(numbers)-1

        while idx1<idx2:
            if numbers[idx1]+numbers[idx2]>target:
                idx2-=1
            elif numbers[idx1]+numbers[idx2]<target:
                idx1+=1
            elif numbers[idx1]+numbers[idx2]==target:
                return [idx1+1,idx2+1]
            else:
                continue
        return [idx1+1,idx2+1]

        # for i in range(len(numbers)):
        #     for j in range(i+1, len(numbers)):
        #         if numbers[i]+numbers[j] == target:
        #             return [i+1,j+1]

        # return [i+1,j+1]
        
        