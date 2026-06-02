class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+= nums[i];
        }
        if(x>sum ) return -1;
        int req = sum-x;
        
        int i = 0;
        int j = 0;
        int maxi = -1;
        sum = 0;
        while(j<nums.size()){
            sum+= nums[j];

            while(sum>req){
                sum-= nums[i];
                i++;
            }
            if(sum == req){
                int count = j-i+1;
                maxi = max(maxi,count);
            }
            j++;

        }
             if(maxi == -1) return -1;



        return  nums.size()- maxi;
       

    
    }
};