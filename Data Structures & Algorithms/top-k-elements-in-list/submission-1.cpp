class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto x:nums){
            count[x]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        for(auto i=count.begin();i!=count.end();i++){
            freq[i->second].push_back(i->first);
        }

        vector<int> ans;
        for(auto i=freq.size()-1;i>=0;i--){
            if(freq[i].size()!=0){
                for(int j=0;j<freq[i].size();j++){
                    ans.push_back(freq[i][j]);

                    if(ans.size()==k){
                        return ans;
                    }
                }   
            }
        }

        return ans;
    }
};
