class Solution {
public:
    int trap(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int l_max =nums[0];
        int r_max = nums.back(); 
        int ans = 0;    
        
        while(l<r){
            if(l_max<r_max){
                l++;
                l_max = max(nums[l], l_max);
                if(l_max-nums[l]>0){
                    ans+=l_max-nums[l];
                }
            } else{
                r--;
                r_max = max(nums[r], r_max);
                if(r_max-nums[r]>0){
                    ans+=r_max-nums[r];
                }
            }
        }

        return ans;
    }
};
