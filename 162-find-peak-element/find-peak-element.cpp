class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start = 1;
        int end = arr.size()-2;
        int mid = start+(end-start)/2;
        int n = arr.size();

        if (n == 1) return 0;
        if(arr[0] > arr[1]) return 0;

        if (arr[n - 1] > arr[n - 2]) return n - 1;

        while(start<=end){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            if(arr[mid]<arr[mid+1]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = start+(end-start)/2;
        }

        return -1;
    }
};