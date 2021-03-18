class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        i = 0
        while i < len(nums)-2:
            print i
            l = self.twoSum(nums[i+1:], nums[i]*(-1))
            for ele in l:
                res.append([nums[i]]+ele)
            i+=1
            while i<len(nums)-2 and nums[i-1]==nums[i]:
                i+=1
        return res
            
    def twoSum(self, nums, target):
        res = []
        i,j = 0,len(nums)-1
        while i<j:
            if nums[i]+nums[j]==target:
                res.append([nums[i],nums[j]])
                i+=1
                while i<len(nums)-2 and nums[i-1]==nums[i]:
                    i+=1
                j-=1
                while j>1 and nums[j]==nums[j+1]:
                    j-=1
            elif nums[i]+nums[j]<target:
                i+=1
                while i<len(nums)-2 and nums[i-1]==nums[i]:
                    i+=1
            else:
                j-=1
                while j>1 and nums[j]==nums[j+1]:
                    j-=1
        return res
