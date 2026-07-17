class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>result;
        int j = 1;
        unordered_map<int,int>mp;
        int n = arr.size();
        vector<int>ans(n);
        for(int i = 0;i<arr.size();i++){
            ans[i] = arr[i];
        }
        sort(ans.begin(),ans.end());
        for(int i = 0;i<n;i++){
            if (mp.find(ans[i]) == mp.end()) {
            mp[ans[i]] = j;
            j++;
             }
        }
         for (int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }
        
        return arr;
    }
};