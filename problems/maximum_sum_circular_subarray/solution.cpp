class Solution {
public:
	int maxSubarraySumCircular(vector<int>&nums) {
		int globalMax = nums[0], globalMin = nums[0];
		int currMax = 0, currMin = 0;
		int total = accumulate(nums.begin(), nums.end(), 0);

		for (auto i : nums) {
			currMax = max(currMax + i, i);
			currMin = min(currMin + i, i);
			globalMax = max(globalMax, currMax);
			globalMin = min(globalMin, currMin);
		}
		return globalMax > 0 ? max(globalMax, total - globalMin) : globalMax;
	}

};