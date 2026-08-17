class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int streak=0, ans=0, no;
        unordered_set<int> _set(nums.begin(), nums.end());

        for(int x: nums){
            if(_set.find(x-1)==_set.end()){
                streak=1; 
                while(_set.find(streak+x)!=_set.end()){
                    streak++;
                }
            }

            ans = max(ans, streak);

        }

        return ans;
    }
};
