class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int count = 0;
        int sum = 0;
        int mini = INT_MAX;
        for (int j = 0;j<nums.size();j++){
            sum+= nums[j];


            while(sum>=target){
                count = j-i+1;
                mini = min(mini,count);
                sum-= nums[i];
                i++;
            }
        }
        if(mini == INT_MAX) return 0;
        return mini;
        

        
    }
};