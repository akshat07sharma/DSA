class Solution {
public:
    vector<long long> dp;

    long long helper(vector<vector<int>>& questions, int i) {
        if (i >= questions.size()) return 0;

        if (dp[i] != -1) return dp[i];

        long long pick =
            questions[i][0] +
            helper(questions, i + questions[i][1] + 1);

        long long skip = helper(questions, i + 1);

        return dp[i] = max(pick, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n, -1);
        return helper(questions, 0);
    }
};