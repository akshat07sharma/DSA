class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        int j = k;
        while(j<s.size()){
            reverse(s.begin()+i , s.begin()+j);
            i += 2*k;
            j+= 2*k;

        }
           if (i < s.size()) {
            reverse(s.begin() + i, s.begin() + min(i + k, (int)s.size()));
        }
        return s;
    }
};