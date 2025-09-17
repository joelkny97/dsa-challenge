class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        n = len(s)
        max_len = 0
        start = 0
        end = 0

        dp = [[False] * n for _ in range(n)]

        for i in range(n):
            for j in range(i+1):
                if s[j] == s[i]:

                    if i-j<= 1 or dp[i-1][j+1]:
                        dp[i][j] = True
                        if max_len < i-j+1:
                            max_len = i-j+1
                            start = j
                            end = i
                    else:
                        dp[i][j] = False

                else:
                    dp[i][j] = False

        
        return s[start:end+1]



        