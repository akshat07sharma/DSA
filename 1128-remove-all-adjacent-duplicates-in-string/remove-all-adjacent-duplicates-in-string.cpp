class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans = "";
        int i = 0;
        for(int i = 0;i<s.size();i++){
            if(!st.empty() && st.top() == s[i]){
                st.pop();            
            }
            else st.push(s[i]);

        }
        while(!st.empty()){
            ans+=st.top();
            i++;
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;

        
    }
};