class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre(n);
        vector<int> suf(n);

        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i]; 
            pre[i]=prod;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i]; 
            suf[i]=prod;
        }

        ans[0] = suf[1];    
        ans.back() = pre[nums.size()-2];    
        for(int i=0;i<nums.size();i++){
            if(i!=0 && i!=nums.size()-1){
                ans[i] = pre[i-1]*suf[i+1];
            }

            // if(i==0)
        }

        return ans;
    }
};
