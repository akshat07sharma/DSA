class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if (n==1) return nums[0];
        vector<int>cost(n,0);
        cost[0] = nums[0];
        cost[1] = max(nums[0],nums[1]);
        
    for(int i = 2;i<nums.size();i++){
       int skiphouse = cost[i-1];
       int robhouse = cost[i-2] + nums[i];

       cost[i] = max(skiphouse,robhouse);

       

    }
    return cost[n-1];
    }
};