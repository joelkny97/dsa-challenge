class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = 0
        n = len(s)
        max_len = 0

        chars = set() # char set to store unique chars

        # use loop to iterate through list
        for end in range(n):

            while s[end] in chars:
                # loop through set and remove chars from left
                chars.remove(s[start])

                # move start pointer 
                start+=1

            # add char to set if not present and calculate max len
            chars.add(s[end]) 
            max_len = max(max_len,end-start+1)


        return max_len
        



