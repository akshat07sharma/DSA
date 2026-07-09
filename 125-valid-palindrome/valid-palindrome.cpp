class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        int i = 0;
        while(i<s.size()){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans.push_back(s[i]);
            }
            else if(s[i]>= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 32;
                ans.push_back(s[i]);
            }
            else if (s[i] >= '0' && s[i]<= '9'){
                  ans.push_back(s[i]);
            }
            
            i++;

           
        }
        int k = 0;
        int j = ans.size()-1;

        while(k<=j){
            if(ans[k] == ans[j]){
                k++;
                j--;
            }

            else {
                return false;
            }
        }
        return true;
    }
};