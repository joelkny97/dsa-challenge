class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        n = len(s)
        self.max_len = 0
        self.start = 0
        self.end = 0
        # DP Approach
        # dp = [[False] * n for _ in range(n)]

        # for i in range(n):
        #     for j in range(i+1):
        #         if s[j] == s[i]:

        #             if i-j<= 1 or dp[i-1][j+1]:
        #                 dp[i][j] = True
        #                 if max_len < i-j+1:
        #                     max_len = i-j+1
        #                     start = j
        #                     end = i
        #             else:
        #                 dp[i][j] = False

        #         else:
        #             dp[i][j] = False

        
        # return s[start:end+1]

        #Two pointer approach

        for i in range(n):
            self.extend_around_center(s, i, i) # odd lengths
            if i<n-1 and s[i] == s[i+1]:
                self.extend_around_center(s, i, i+1) # even lengths

        return s[self.start:self.end+1]

        
    def extend_around_center(self, s: str, left: int, right: int):
        while left>=0 and right<=len(s)-1 and s[left] == s[right]:
            left-=1
            right+=1

        left+=1
        right-=1

        if self.max_len < right-left+1:
            self.max_len = right-left+1
            self.start = left
            self.end = right

        




        