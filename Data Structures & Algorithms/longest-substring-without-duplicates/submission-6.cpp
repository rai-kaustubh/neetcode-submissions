class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int l=0, r=1;
        int ans=1;
        unordered_set<char> _set;
        _set.insert(s[l]);
        while(r<s.size()){
            if(_set.find(s[r])==_set.end()){
                _set.insert(s[r]);
                ans = max(ans, r-l+1);
                r++;
                continue;
            }
            if(s[l]==s[r]){
                l++;
                r++;
                continue;
            }
            while(s[l]!=s[r]){
                _set.erase(s[l]);
                l++;
            };
            l++;
            r++;
        }

        return ans;
    }
};
