class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        res = 1
        lis = set()
        
        for i in range(len(num)):
            lis.add(num[i])
        
        for i in range(len(num)):
            s = num[i]
            e = num[i]
            while s+1 in lis:
                s = s + 1
                lis.remove(s)
            while e-1 in lis:
                e = e - 1
                lis.remove(e)
            res = max(res, s - e + 1)
        
        return res