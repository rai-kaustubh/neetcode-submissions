class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;

        while(l<r){
            if(!isalnum(s[l])){
                l++; continue;
            }
            if(!isalnum(s[r])){
                r--;continue;
            }
            s[l]=tolower(s[l]);
            s[r]=tolower(s[r]);
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
