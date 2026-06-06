class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left;
        
        int n = height.size();
        vector<int>right(n);
 
        
        int maxi= INT_MIN;
        int i = 0;
        while(i<height.size()){
            int curr = height[i];
            maxi = max(curr,maxi);
            left.push_back(maxi);
            i++;
        }
        i = n-1;
        maxi= INT_MIN;
        while(i>=0){
            int curr = height[i];
            maxi = max(curr,maxi);
            right[i] = maxi;
            i--;

        }
        i = 0;
        int sum = 0;
        while(i<n){
            sum+= min(left[i],right[i])-height[i];
            i++;

        }
        return sum;
    }
};