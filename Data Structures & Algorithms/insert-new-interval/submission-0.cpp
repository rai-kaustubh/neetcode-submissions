class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    /*
        vector<vector<int>> ans;
        iterate all intervals{
            interval[1]<nI[0] {
                insert into ans;
            }

            if interval[0]>ni[1]{
                insert ni, then all intervals after and return
            }
            
            else{
                ni[0] = min(interval[0], ni[0])
                ni[1] = max(interval[1], ni[1])
            }

        }

        ans.push_back(ni)

        return ans;
    
    */

        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            } else if (intervals[i][0]> newInterval[1]){
                ans.push_back(newInterval);
                copy(intervals.begin()+i, intervals.end(), back_inserter(ans));
                return ans;
            } else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);       
            }
        }

        ans.push_back(newInterval);
        return ans;
        


    }
};
