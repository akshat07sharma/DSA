class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 1;
        int candidate = arr[0];
        for(int i = 1;i<arr.size();i++){
            if(arr[i]==candidate){
                count++;
            }
            else if(arr[i]!= candidate){
                count--;
            }
            if(count==0){
                candidate = arr[i];
                count = 1;

            }
        }
        return candidate;
    }
};