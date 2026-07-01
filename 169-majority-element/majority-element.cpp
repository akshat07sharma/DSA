class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0;
        int candidate = arr[0];
        for(int i = 0;i<arr.size();i++){
            if(count ==0){
                candidate = arr[i];
            }
            if(arr[i]==candidate) count++;
            else count--;
        }
        return candidate;
         
    }
};