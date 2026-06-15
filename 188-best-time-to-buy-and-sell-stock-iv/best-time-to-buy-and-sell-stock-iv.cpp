class Solution {
public:

    using vi = vector<int>;
    using vvi = vector<vector<int>>;
    using vvvi = vector<vector<vector<int>>>;

    int helper(vector<int>& prices, int day, int state,
               int k, vvvi& memo) {

        if(day >= prices.size() || k == 0)
            return 0;

        if(memo[day][state][k] != -1)
            return memo[day][state][k];

        int profit = 0;

        if(state == 0) {
            int buy = -prices[day] +
                      helper(prices, day + 1, 1, k, memo);

            int dontbuy =
                      helper(prices, day + 1, 0, k, memo);

            profit = max(buy, dontbuy);
        }
        else {
            int hold =
                      helper(prices, day + 1, 1, k, memo);

            int sell = prices[day] +
                       helper(prices, day + 1, 0, k - 1, memo);

            profit = max(hold, sell);
        }

        return memo[day][state][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vvvi memo(n, vvi(2, vi(k + 1, -1)));

        return helper(prices, 0, 0, k, memo);
    }
};