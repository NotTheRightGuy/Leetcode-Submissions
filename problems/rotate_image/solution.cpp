class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // by Using extra space
        int n = matrix.size();
        vector<vector<int>> matrixCopy(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][n - 1 - i] = matrixCopy[i][j];
            }
        }
    }
};