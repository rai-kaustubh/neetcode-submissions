class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(r<nums.size() && l<=r){
            int mid =l+((r-l)/2);
            if(nums[mid]==target){
                return mid;
            }

            if(nums[mid]>target){
                r=mid-1;
            } else{
                l=mid+1;
            }
        }

        return -1;
    }
};
/*

nums=[-1,0,2,4,6,8]
target=4

l=0
r=5
mid =2
*/
