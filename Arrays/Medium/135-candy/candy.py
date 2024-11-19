class Solution:
    def candy(self, ratings: List[int]) -> int:
        if len(ratings)==1:
            return 1

        # start=1
        # next_idx = start+1
        # pre_idx = start-1
        # end = len(ratings)-1
        # candies=len(ratings)
        # bonus=0
        # while start<end-1:
                
        #     if ratings[start] > max(ratings[pre_idx] , ratings[next_idx]):
        #         bonus+=1
        #         candies+=bonus
        #     start+=1
        #     next_idx += 1
        #     pre_idx +=1
        # return candies

        candies, up, down, peak = 1, 0, 0, 0
        
        for prev, curr in zip(ratings[:-1], ratings[1:]):
            if prev < curr:
                up, down, peak = up + 1, 0, up + 1
                candies += 1 + up
            elif prev == curr:
                up = down = peak = 0
                candies += 1
            else:
                up, down = 0, down + 1
                candies += 1 + down - int(peak >= down)
        
        return candies