class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        pre = [0] * n
        suf = [0] * n
        pre[0] = suf[-1] = 1
        for i in range(1,n):
            pre[i] = nums[i-1]*pre[i-1]
        for i in range(n-2,-1,-1):
            suf[i] = nums[i+1]*suf[i+1]
        for i in range(n):
            res[i] = pre[i]*suf[i]
        return res