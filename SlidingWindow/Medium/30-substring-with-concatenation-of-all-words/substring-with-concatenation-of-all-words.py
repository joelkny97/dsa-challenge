from collections import Counter, defaultdict

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words or not s:
            return []
        word_len = len(words[0])
        total_words = len(words)
        substr_len = word_len * total_words

        word_count=Counter(words)

        res=[]
        # i = 0

        # while i < len(s):
        #     checks = words.copy()
        #     # print(checks)
        #     j=i
        #     while checks:
        #         curr = s[j:j+word_len]
        #         # print(curr)
        #         if curr not in checks:
        #             break
        #         else:
        #             checks.remove(curr) # remove from check list
        #             j+=word_len
            
            
        #     if not checks:
        #         res.append(i)
        #         # success=j
        #     i+=1
        # Slide window starting from each possible offset within a word's length
        for start in range(word_len):
            left = start  # Left boundary of the window
            right = start  # Right boundary of the window
            curr_count = Counter()  # Count words in the current window
            matched_words = 0  # Track the number of valid words

            while right + word_len <= len(s):
                word = s[right:right + word_len]  # Extract next word
                right += word_len  # Move right boundary

                if word in word_count:
                    curr_count[word] += 1

                    # If we have more than required, slide left pointer
                    while curr_count[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        curr_count[left_word] -= 1
                        left += word_len

                    if right - left == substr_len:  # If valid window
                        res.append(left)
                else:
                    # If invalid word, reset window
                    curr_count.clear()
                    left = right  # Start fresh from next word

        return res

            
                
            
                
        