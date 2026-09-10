class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // min heap <freq, int>;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        unordered_map<int, int> mp;
        for(auto num: nums){
            mp[num]++;
        }

        for(auto &[key, val]: mp){
            pq.push({val, key});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
