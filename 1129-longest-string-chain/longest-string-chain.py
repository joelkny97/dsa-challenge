class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        
        if words is None or len(words)==0:
            return 0

        dp = {}

        words.sort(key=len)

        longest = 1

        for word in words:
            dp[word] = 1
            for i in range(len(word)):
                pred = word[:i] + word[i+1:]
                if pred in dp:
                    dp[word] = max(dp[word], dp[pred]+1)

            longest = max(longest, dp[word])

        return longest

        