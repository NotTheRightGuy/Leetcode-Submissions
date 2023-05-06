class Solution {
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int total = 0, length = nums.length, left = 0, right = length - 1,mod=1000000007;
        int[] var = new int[length];
        var[0] = 1;
        for (int i = 1; i < length; i++) {
            var[i] = var[i - 1] * 2 % mod;
        }
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else {
                total = (total + var[right - left++]) % mod;
            }
        }
        return total;
    }
}