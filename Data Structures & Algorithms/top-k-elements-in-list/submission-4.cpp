class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> _map;
        for(auto num:nums){
            _map[num]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        
        for(auto i=_map.begin();i!=_map.end();i++){
            freq[i->second].push_back(i->first);
        }
        vector<int> ans={};

        for(int i=freq.size()-1;i>=0;i--){
            if((int)freq[i].size()>0){
                for(int j=0;j<(int)freq[i].size();j++){
                    if(ans.size()<k){
                        ans.push_back(freq[i][j]);
                    } else{
                        return ans;
                    }
                }        
            }
        }

        return ans;
    }
};
/*
nums = [7,7], k = 1

_map:
7:2

0->[]
1->[]
2->[]
3->[]

ans: 3, 2

*/
