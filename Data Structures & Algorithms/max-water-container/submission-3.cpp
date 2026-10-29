class Solution {
public:
    int maxArea(vector<int>& nums) {
        int max_area = 0;
        int l=0, r=nums.size()-1;

        while(l<r){
            int area = min(nums[l], nums[r])*(r-l);
            max_area = max(max_area, area);

            if(nums[l]< nums[r]){
                l++; 
                continue;
            }
            r--;
        }

        return max_area;
    }
};
/*
    Input: height = [1,7,2,5,4,7,3,6]
    l=0, r=nums.size()-1;
    area = 7*1 =7

*/
