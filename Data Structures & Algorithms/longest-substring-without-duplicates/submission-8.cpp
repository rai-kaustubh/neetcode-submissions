class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int len = 1, l=0, r= 0;
        unordered_set<char> uo_set;
        
        while(r<s.size()&& l<=r){
            if(!uo_set.count(s[r])){
                uo_set.insert(s[r]);
                len = max(r-l+1, len);
                r++;
            } else{
                while(l<=r && s[l]!=s[r]){
                    uo_set.erase(s[l]);
                    l++;
                }
                l++;
                r++;
            }

        }

        return len;
    }
    /*
        pwwkew
        uo_set = w
        len = 1;
        l=2, r=2
    */
};
