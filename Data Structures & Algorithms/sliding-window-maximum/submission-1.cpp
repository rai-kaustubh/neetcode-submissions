class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> or_set;
        int l=0, r=0;
        vector<int> ans;

        while(r<k){
            or_set[(nums[r])]++;
            r++;            
        }
        ans.push_back(or_set.rbegin()->first);
        
        while(r<nums.size() && l<=r){
            or_set[(nums[r])]++;
            or_set[(nums[l])]--;
            if(!or_set[nums[l]]){
                or_set.erase(nums[l]);
            }
            l++;
            ans.push_back(or_set.rbegin()->first);
            r++;
        }

        return ans;
    }
};

/*
Input: nums = [-7,-8,7,5,7,1,6,0], k = 4
l=0
r=4
k=4
set= -7, -8, 7,5
ans = 




*/
