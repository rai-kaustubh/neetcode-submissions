class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r && r<nums.size()){
            int mid = l+(r-l)/2;
            if(nums[mid]==target) return mid;

            if(nums[l]<=nums[mid]){
                if( target>=nums[l] && target<nums[mid]){
                    r=mid-1;
                } else{
                    l=mid+1;
                }
            } else{
                if(target<=nums[r]&& target>nums[mid]){
                    l= mid+1;
                } else{
                    r=mid-1;
                }
            }
        }

        return -1;
    }
};
/*
nums = [3,4,5,6,1,2], target = 1
l=0
r=5
mid = 3

if(nums[l]<nums[mid])
    if( target<nums[mid]){
        r=mid-1;
    } else{
    l=mid+1}
} else{
    if(target<nums[r]){
        r= mid+1;
    } else{
        l=mid-1}
}
*/
