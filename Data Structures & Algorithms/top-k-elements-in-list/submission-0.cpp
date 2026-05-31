class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> _count;
        for(auto num:nums){
            _count[num]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        for(auto i=_count.begin();i!=_count.end();i++){
            freq[i->second].push_back(i->first);
        }

        vector<int> res;
        for(int i=freq.size()-1;i>0;i--){
            if(freq[i].size()!=0){
                for(int j : freq[i]){
                    res.push_back(j);
                    if(res.size()==k) return res;
                }
            }
        }

        return res;
    }
};
