class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()), post(nums.size());
        // compute pre
        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            pre[i]=prod;
        }
        // compute post
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            post[i]=prod;
        }

        // prod of arr except self
        vector<int> res(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i!=0 && i!=nums.size()-1){
                res[i]=pre[i-1]*post[i+1];
                cout<<res[i];
                continue;
            }
            if(i==0){
                res[i]=post[i+1];
            }
            else {
                res[i]=pre[i-1];
            }
        }

        return res;
    }
};
