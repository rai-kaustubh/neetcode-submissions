class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        for(auto interval: intervals){
            if(ans.size()==0 || interval[0]>ans.back()[1]){ //no overlap
                ans.push_back(interval);
            }

            vector<int> toInsert(2);
            ans.back()[0] = min(interval[0], ans.back()[0]);
            ans.back()[1] = max(interval[1], ans.back()[1]);

            // ans.push_back(toInsert);
        }

        return ans;
    }
};
