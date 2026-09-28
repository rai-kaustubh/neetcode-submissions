class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=INT_MAX;
        int l =1, r=*max_element(piles.begin(), piles.end());
        while(l<=r){
            int mid =l+(r-l)/2;
            int hrs=0;
            for(int i=0;i<piles.size();i++){
                hrs+=piles[i]/mid;
                if(piles[i]%mid>0)
                    hrs++;
            }

            if(hrs<=h){
                r=mid-1;
                ans =min(ans, mid);
            } else{
                l=mid+1;
            }
        }

        return ans;
    }
};
/*
piles = [1,4,3,2], h = 9
r=4;
l=1;
mid = 2
*/
