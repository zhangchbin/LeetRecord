class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        for i in range(1<<len(nums)):
            tmp = []
            s = i
            cur=0
            while s>0:
                if s%2==1:
                    tmp.append(nums[cur])
                cur+=1
                s >>=1
            ans.append(tmp)
        return ans
