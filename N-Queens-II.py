class Solution(object):
    def __init__(self):
        self.res = 0
    
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.dfs(n,0,[])
        return self.res
        
    def dfs(self, n, count, pos):
        if len(pos) == n:
            self.res += 1
            return
        for i in range(n):
            if self.validate(count,i,pos):
                pos.append((count, i))
                self.dfs(n,count+1,pos)
                pos.pop(-1)
        return
            
    def validate(self, x, y, pos):
        for (i, j) in pos:
            if y==j or (x+y)==(i+j) or (x-y)==(i-j):
                return False
        return True
