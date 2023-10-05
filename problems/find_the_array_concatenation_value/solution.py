class Solution:
    def findTheArrayConcVal(self, nums) -> int:
        ans = 0
        left = 0
        right = len(nums) - 1
        while (left <= right):
            if (left != right):
                ans += int(str(nums[left]) + str(nums[right]))
            else:
                ans += nums[left]
            left += 1
            right -= 1
        return ans