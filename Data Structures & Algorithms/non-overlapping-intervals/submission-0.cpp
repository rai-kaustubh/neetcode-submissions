class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count= 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        
        vector<vector<int>> ans;
        for(auto interval: intervals){
            if(ans.size()==0 || ans.back()[1]<=interval[0]){
                ans.push_back(interval);
            } else {
                count++;
            }
        }

        return count;
    }
};
