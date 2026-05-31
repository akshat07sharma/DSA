class Solution {
public:
    string minWindow(string s, string t) {
         int n = s.length();
         int m = t.length();
         int left = 0;
         int right = 0;
         int count = 0,start = 0;
         int len = INT_MAX;
         vector<int>freq(128,0);

         for(char ch :t){
            freq[ch]++;
         }
         if(m>n) return "";
         while(right<n){
            if(freq[s[right]]>0){
                count++;
            }
            freq[s[right]]--;
            
            while(count==m){
                if(right-left+1<len){
                    len = right-left+1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0){
                    count--;
                   
                }
                left++;
            

            }
                right++;
        
         }
         if(len==INT_MAX) return "";
         return s.substr(start,len);




    }
};