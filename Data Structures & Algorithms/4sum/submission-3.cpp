class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans = {};
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<nums.size();j++){
                if(j> i+1 && nums[j]==nums[j-1]) continue;

                long long to_find = (long long) target-nums[i]-nums[j];

                int l=j+1, r=nums.size()-1;
                
                while(l<r){
                    if((long long )nums[l]+nums[r]==to_find){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;    
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    } else if((long long ) nums[l]+nums[r]>to_find){
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};
/*
    
    nums = [-3,0,1,2,3,3], target = 3
    ans = [{-3,0, 3, 3}, {}]

    i=0(-3)
    j=2(1)
    toFind = target-sum[i+j] = 5
    
    l=4(3), r=5(3)

    if(l==i ||l==j){
        l++
    }
    if(r==i ||r==j){
        r--;
    }

    if(nums[l]+nums[r]==toFind){
        ans.push({i,j,l,r});
    } else if(nums[l]+nums[r]>toFind){
        r--;
    } else {
        l++;
    }

    return ans;





    
*/