class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for(char c: s1){
            map1[c]++;
        }
        // cout<<map1.size();
        
        int l=0, r=s1.size()-1;
        while(r<s2.size()){
            for(int i=l;i<=r;i++){
                if(map1.find(s2[i])==map1.end()){
                    map2.clear();
                    l=i+1;
                    r = l+s1.size()-1;
                    break;
                }

                map2[s2[i]]++;
            }

            int count=0;
            for(auto x: map2){
                cout<<x.first<<"->"<<x.second<<endl;
                if(map1[x.first]!=map2[x.first]){
                    map2.clear();
                    l=l+1;
                    r = l+s1.size()-1;
                    break;
                }
                count++;
            }
            cout<<(count==2)<<endl;
            if(count==map1.size()) return true;
        }

        return false;
    }
};
