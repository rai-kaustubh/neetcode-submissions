class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0 ,r=0, len = 0, max_freq=0;
        unordered_map<char, int> freq;

        while(r<s.size() && l<=r)    {
            freq[s[r]]++;
            max_freq = max(max_freq, freq[s[r]]);
            if(r-l+1-max_freq<=k){
                len = max(len, r-l+1);
                r++;
            } else{
                while(l<=r && r-l+1-max_freq>k){
                    // if(freq[s[l]]==max_freq){
                    // x    max_freq--;
                    // }
                    freq[s[l]]--;
                    l++;
                }
                    r++;
            }
        }
        return len;
    }
    /*
        ABAA
        k=0,
        l=1
        r=1,
        len=1
        max_freq=0
        a-0
        b-1

    */
};
