class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1;
        while(l<=r&&r<nums.size()){
            if(l==r){
                return nums[l];
            }

            int mid = l+(r-l)/2;

            if(mid!=0 && nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid-1;
            }

        }

        return nums[l];
    }
};
/*
nums = [4,5,6,7]
l=0,r=5;

if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
return nums[mid]}
nums[mid]>nums[r] -> l=mid+1;
else{
    r=mid-1;
}

*/
