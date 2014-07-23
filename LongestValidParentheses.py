class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        stk=[]
        res=0
        count=0
        for i in s:
            if i=='(':
                stk.append(count)
                count=0
            elif len(stk)!=0:
                count+=(1+stk[-1])
                del stk[-1]
                res=max(res,count)
            else:
                count=0
        return res*2

