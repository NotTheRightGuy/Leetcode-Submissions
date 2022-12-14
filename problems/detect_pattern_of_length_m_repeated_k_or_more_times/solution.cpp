class Solution
{
public:
	bool containsPattern(vector<int>& arr, int m, int k) {
		int curr = 0;
		for (int i = 0; i + m < arr.size(); i++) {
			if (arr[i] == arr[i + m])curr++;
			else curr = 0;
			if (curr / m == k - 1 && curr % m == 0) return true;
		}
		return false;
	}
};