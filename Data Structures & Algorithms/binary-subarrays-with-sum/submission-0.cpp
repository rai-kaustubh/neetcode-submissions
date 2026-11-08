class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal!=0)
            return helper(nums, goal) - helper(nums, goal-1);
        
        return helper(nums, 0);
    }

    int helper(vector<int>& nums,  int goal){
        int ans = 0;

        int l=0,r=0, currSum = 0;
        while(r<nums.size()){
            currSum += nums[r];

            while(currSum>goal){
                currSum-=nums[l];
                l++;
            }   

            ans+=r-l+1;
            r++;
        }

        return ans;
    }
};