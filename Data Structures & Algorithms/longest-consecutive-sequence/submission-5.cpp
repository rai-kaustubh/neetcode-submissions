class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //[0,,,,,,]

        unordered_set st(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int len;
            if(!st.count(nums[i]-1)){
                st.erase(nums[i]);
                len=1;
                while(st.count(nums[i]+len)){
                    st.erase(nums[i]+len);
                    len++;
                }    
            }
            ans =max(ans, len);
        }
    
        return ans;
    }
};
