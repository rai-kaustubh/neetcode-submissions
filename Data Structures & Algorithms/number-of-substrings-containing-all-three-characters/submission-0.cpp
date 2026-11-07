class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        unordered_map<char, int> freq;
        int ans=0;

        int l=0,r=0;
        while(r<s.size() && l<=r){
            if(freq[s[r]]++ == 0){
                count++;
            }

            if(count==3){ // shrink
                ans+=s.size()-r;
                while(l<=r && count==3){
                    if(freq[s[l]]-- ==1){
                        count--;
                        l++;
                        break;
                    } else{
                        ans+=s.size()-r;
                        l++;
                    }
                }
            }

            r++;
        }

        return ans;
    }
};
/*
    abcabc
    l=0
    r=0
    count = 
    a->
    b->
    c->
*/
