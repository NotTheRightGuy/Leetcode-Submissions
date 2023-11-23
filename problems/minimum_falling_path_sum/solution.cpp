class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&matrix) {
	int n = matrix.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		dp[0][i] = matrix[0][i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int curr = matrix[i][j];
			if (j - 1 < 0) {
				dp[i][j] = curr + min(dp[i - 1][j], dp[i - 1][j + 1]);
			}
			else if (j + 1 >= n) {
				dp[i][j] = curr + min(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			else {
				dp[i][j] = curr + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1]));
			}
		}
	}

	int mini = 1e9;
	for (int i = 0; i < n; i++) {
		mini = min(dp[n - 1][i], mini);
	}
	return mini;

}
};