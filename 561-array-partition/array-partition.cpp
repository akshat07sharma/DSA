class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        int sum = 0;
        int i = 0;

        while(i<nums.size()){
           int ans = min(nums[i],nums[i+1]);
           sum+= ans;
           i+=2;
          
        }
        return sum;
    }
};