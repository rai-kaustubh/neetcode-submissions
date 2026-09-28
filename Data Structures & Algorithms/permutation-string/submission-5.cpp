class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> uo_mapS1;
        for(char c: s1){
            uo_mapS1[c]++;
        }

        int l=0, r=0;
        unordered_map<char, int> uo_mapS2;
        while(r<s2.size() && l<=r){
            if(!uo_mapS1.count(s2[r])){
                l=r+1;
                r++;
                uo_mapS2.clear();
                continue;

            }

            while(r-l+1>s1.size()){
                uo_mapS2[s2[l]]--;
                l++;
            }

            uo_mapS2[s2[r]]++;
            if(uo_mapS1.size() ==uo_mapS2.size()){
                int f=false;
                for(auto &[k,v]: uo_mapS1){
                    if(uo_mapS2[k]!=v){
                        f=true;
                        break;

                    }
                }

                if(!f) return true;
            }

            
            r++;

        }

        return false;

    }
    /*
    s1 = "abc", s2 = "aabbcca"
    a-1
    b-1
    c-1

    left=0
    right=0
    a-1
    b-2
    c-1
    
    if(map.count(s2[r])==map.end()){
        l=r+1;
        r++;
    } else{
        s2[r]++;
    }

    if(s1.map.size() = s2.map.size()){

    }
    
    
    
    */
};
