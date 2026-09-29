class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[nums[0]],slow=nums[0];
        
        while(slow!=fast){
            fast=nums[nums[fast]];
            slow=nums[slow];
        }

        fast=0;
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

/*
fast=0;
slow=0;

fast= nums[nums[fast]];
slow = nums[slow];

0-1-2-3-4-4

*/
