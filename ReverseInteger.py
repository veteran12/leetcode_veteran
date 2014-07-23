class Solution:
    # @return an integer
    def reverse(self, x):
        tmp = x
        if tmp < 0:
            positive = False
            tmp = tmp * -1
        else:
            positive = True
        res = 0
        while tmp > 0:
            res = (res * 10 + tmp % 10)
            tmp = tmp / 10
            
        if positive:
            return res
        else:
            return -res

