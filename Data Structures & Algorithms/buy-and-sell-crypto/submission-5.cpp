class Solution {
public:
    int maxProfit(vector<int>& prices) {

    /*
        10,1,5,6,7,1
         0,6,2,1,0,0          
        r_max =7;

    
    */
        int profit =0, r_max = prices.back();
        for(int i=prices.size()-1; i>=0;i--){
            if(prices[i]>r_max){
                r_max = prices[i];
                continue;
            }

            profit = max(profit, r_max-prices[i]);
        }

        return profit;

    }
};
