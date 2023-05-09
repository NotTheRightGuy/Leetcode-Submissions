class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        if (l == r)
            return l;
        if (nums.length == 1)
            return 0;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1]) {
                r = mid;
                System.gc();
            } else {
                l = mid + 1;
            }
        }
        System.gc();
        return l;
    }
}