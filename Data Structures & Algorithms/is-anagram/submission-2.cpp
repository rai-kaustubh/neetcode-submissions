class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26);
        for(char x : s){
            vec[x-'a']++;
        }
        for(char x : t){
            vec[x-'a']--;
        }

        for(auto x: vec){
            if (x!=0){
                return false;
            }
        }

        return true;


    }
};
