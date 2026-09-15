class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i=0;i<=n;i++){   
            int ones = 0;
            auto x = i;
            
            while(x>0){
                ones+=(x&1);
                x>>=1;
            }
            res.push_back(ones);
        }

        return res;
    }
};
