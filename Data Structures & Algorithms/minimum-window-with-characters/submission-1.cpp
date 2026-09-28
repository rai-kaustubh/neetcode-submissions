class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;
        for(char c:t){
            countT[c]++;
        }

        int len = INT_MAX, idx=-1;

        int l=0, r=0, have=0,need = countT.size();
        
        while(l<=r && r<s.size()){
            char c = s[r];
            window[c]++;
            if(countT.count(c) && countT[c]==window[c]){
                have++;
            }

            while(l<=r && have == need){
                if( r-l+1<len){
                    len = r-l+1;
                    idx=l;
                }

                window[s[l]]--;
                if(countT.count(s[l]) && countT[s[l]]>window[s[l]]){
                    have--;
                }
                l++;
            }
            
            r++;
        }

        return len ==INT_MAX?"":s.substr(idx, len);
    }
};

/*
s="aaaaaaaaaaaabbbbbcdd"
t="abcdd"
a-1
b-1
c-1
d-2

l=0
r=17
len=inf
ind = -1
have = 4
a-12
b-5
c-1
d-2

*/
