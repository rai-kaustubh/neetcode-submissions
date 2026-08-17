class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int l=0, r=1, minimum=prices[0], ans=0;

        while(r<prices.size()){
            if(prices[r]<minimum){
                minimum = prices[r];
                r++;
                continue;
            }

            ans = max(ans, prices[r]-minimum);
            r++;


        }

        return ans;
    }
};
