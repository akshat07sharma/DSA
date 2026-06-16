class Solution {
public:
     vector<vector<vector<int>>> dp;
    int helper(vector<string>& strs, int i, int m, int n) {
        if (i == strs.size()) return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];


        int skip = helper(strs, i + 1, m, n);

        int c0 = count(strs[i].begin(), strs[i].end(), '0');
        int c1 = strs[i].size() - c0;

        int pick = 0;
        if (c0 <= m && c1 <= n) {
            pick = 1 + helper(strs, i + 1, m - c0, n - c1);
        }
        return dp[i][m][n] = max(skip, pick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int sz = strs.size();

        dp.resize(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return helper(strs, 0, m, n);
    }
};