class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        /*
            -2, 0, 0, 2, 2            

        
        */
        for(int i=0;i<nums.size();i++){
            int target = -nums[i];
            int l=i+1,r = nums.size()-1;
            
            if(i!=0 and nums[i]==nums[i-1]) continue;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int toComp = nums[l];
                    while(l<nums.size() && nums[l]==toComp ){
                        l++;

                    }
                    r--;
                }

                else if(nums[l]+nums[r]>target){
                    r--;
                }else{
                    l++;
                }
            }
            
        }

        return ans;
    }


};
