class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // min heap <freq, int>;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size()+1);
        for(auto num: nums){
            mp[num]++;
        }

        for(auto &[key, val]: mp){
            freq[val].push_back(key);
        }

        vector<int> ans;
        for(int i=nums.size();i>=0;i--){
            for(int n: freq[i]){
                ans.push_back(n);
                if(ans.size()==k){
                    return ans;
                }
            }
        }

        return ans;
    }
};
