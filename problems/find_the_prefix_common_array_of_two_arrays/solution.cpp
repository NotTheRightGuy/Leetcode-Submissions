
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        bitset<51> mask;
        int n = A.size();
        vector<int> ans(n);
        int idx = 0;
        int curr;
        while (idx < n)
        {
            if (idx == 0)
            {
                if (A[idx] == B[idx])
                    ans[idx] = 1;
                mask.set(A[idx]);
                mask.set(B[idx]);
            }
            else
            {
                curr = 0;
                if (mask.test(A[idx]))
                {
                    curr++;
                }
                mask.set(A[idx]);
                if (mask.test(B[idx]))
                {
                    curr++;
                }
                mask.set(B[idx]);
                ans[idx] = curr + ans[idx - 1];
            }
            idx++;
        }
        return ans;
    }
};