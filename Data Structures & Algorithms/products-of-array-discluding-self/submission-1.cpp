class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()), post(nums.size());
        int prod=1;
        // pre = 1, 2, 8, 48
        // post = 48,48,24, 6 
        // nums=48, 24, 12, 8
        
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            pre[i]=prod;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            post[i]=prod;
        }

        vector<int> res(nums.size());
        for(int i=1;i<=nums.size()-2;i++){
            res[i]=pre[i-1]*post[i+1];
        }

        res[0]=post[1];
        res[nums.size()-1]=pre[nums.size()-2];

        return res;    
    }
};
