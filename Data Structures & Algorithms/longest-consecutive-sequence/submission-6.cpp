class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int curr;
        int max_len=1;
        
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            if(!st.count(curr-1)){
                int len=1;
                while(st.count(curr+len)){
                    len++;
                }
                max_len = max(len, max_len);
            }

        }

        return max_len;
    }
};
/*
    Input: nums = [2,20,10,3,4,4,5]
    curr_ele = 2
    length = 4
    max_length=4;
*/
