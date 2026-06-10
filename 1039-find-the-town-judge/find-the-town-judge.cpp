class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);

        for(auto p: trust ){
            outdeg[p[0]]++;
            indeg[p[1]]++;
        }
        for(int i = 1;i<n+1;i++){
            if(indeg[i]==n-1 && outdeg[i]==0){
                return i;
            }

        }


    return -1;
    }
};