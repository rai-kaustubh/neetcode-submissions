class Solution {
public:
    bool isPalindrome(string s) {
        string pal="";
        for(char c: s){
            if(isalnum(c) && c!=' '){
                pal+=tolower(c);
            }
        }

        for(int i=0;i<pal.length()/2;i++){
            if(pal[i]!=pal[-i-1+pal.length()]) return false;
        } 

        return true;
    }
};
