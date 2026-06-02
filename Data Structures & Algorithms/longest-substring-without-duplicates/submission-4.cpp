class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_set<char> _set;
        int l=0,r=1,_max=1, len=1;
        _set.insert(s[0]);
        
        while(r<s.length() && l<=r){
            if(_set.find(s[r])==_set.end()){
                len++;
                _set.insert(s[r]);
                r++;
                _max = max(_max, len);
            } else {
                len++;
                while(s[l]!=s[r]){
                    _set.erase(s[l]);
                    len--;
                    l++;
                }
                l++;
                len--;
                r++;
            }
        }

        return _max;
    }
};
