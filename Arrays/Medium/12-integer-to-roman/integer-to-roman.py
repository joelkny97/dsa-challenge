class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbols = [
            (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
            (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'), (10, 'X'),
            (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
        ]
        
        res = []

        for value, symbol in value_symbols:
            if num == 0:
                break
            count = num // value
            res.append(symbol * count)
            num -= count * value

        return ''.join(res)

        # roman_nums = {1:'I', 5:'V', 10:'X', 50:'L', 100:'C', 500:'D',1000:'M'}

        # rom = []
        # curr=str(num)
        # no_of_digits=len(curr)
        # place=no_of_digits-1
        # for i in range(no_of_digits):
        #     if place<1:
        #         break

        #     if i < no_of_digits-1 and int(curr[i])*10**(place) < int(10**(place+1)) and place<3:
               
        #         print("first")
        #         print(place)
        #         pre = roman_nums[int(10**(place+1))//2]
        #         print(pre)
        #         numer = ((int(10**(place+1))//2) % int(curr[i])*10**(place))
        #         print(numer)
        #         post_n = numer //(int(10**(place)))
        #         print(post_n)
        #         post = roman_nums[10**(place)] * post_n
        #         print(post)
        #         rom.append(pre+post)
        #         print(rom)
        #     else:
        #         print(place)
        #         rom.append(roman_nums[10**(place)]*int(curr[i]))
        #         print(rom) 
        #     place -=1

        # return rom

        