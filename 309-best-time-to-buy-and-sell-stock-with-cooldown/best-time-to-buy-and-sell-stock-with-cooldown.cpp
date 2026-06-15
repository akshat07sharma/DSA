class Solution {
public:

    int helper(vector<int>& prices, int day, bool state,
               vector<vector<int>>& memo) {

        if(day >= prices.size())
            return 0;

        if(memo[day][state] != -1)
            return memo[day][state];

        int profit = 0;

        if(state == 0) {
            int buy =  -prices[day] + helper(prices, day + 1, 1, memo);
            int dontbuy = helper(prices, day + 1, 0, memo);

            profit = max(buy, dontbuy);
        }
        else {
            int hold = helper(prices, day + 1, 1, memo);
            int sell = prices[day] + helper(prices, day + 2, 0, memo);

            profit = max(hold, sell);
        }

        return memo[day][state] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> memo(n, vector<int>(2, -1));

        return helper(prices, 0, 0, memo);
    }
};