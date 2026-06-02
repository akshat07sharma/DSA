class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (x > sum)
            return -1;

        int req = sum - x;

        int i = 0, j = 0;
        int currSum = 0;
        int maxi = -1;

        while (j < nums.size()) {
            currSum += nums[j];

            while (currSum > req) {
                currSum -= nums[i];
                i++;
            }

            if (currSum == req) {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }
        int ans = nums.size() - maxi;
        if (maxi == -1)
            return -1;

        return ans;
    }
};