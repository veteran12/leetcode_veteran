class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        total, i = 0, 0
        while True:
            cur = 9*pow(10,i)*(i+1) # 9,90,900...9*10^n*(n+1)
            if total+cur >= n:
                break
            total+=cur
            i+=1
        
        if (n-total)%(i+1):
            target=pow(10,i)-1+(n-total)/(i+1)+1
            pos=(i+1)-(n-total)%(i+1)+1
            while pos-1:
                target=target/10
                pos-=1
        else:
            target=pow(10,i)-1+(n-total)/(i+1)
        return target%10
