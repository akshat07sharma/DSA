class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        int count = 0;
        int i = 0;

        while(i<costs.size()){
            if(ans+costs[i]<=coins){
                ans+= costs[i];
                count++;  
            }
            else {
                break;
            }
            i++;
        }
        return count;
    }
};