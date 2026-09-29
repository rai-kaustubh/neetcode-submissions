class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<pair<int,int>> st;
        int max_area=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(st.empty()) {
                st.push({i, nums[i]});
                continue;
            }
            int idx=i, val;
            while(!st.empty() && nums[i]<st.top().second){
                idx = st.top().first;
                val = st.top().second;
                int area= (i-idx)*val;
                max_area = max(area, max_area);
                st.pop();
            }        
            st.push({idx, nums[i]});
        }

        while(!st.empty()){
            auto &[idx, val] = st.top();
            int area= (nums.size()-idx)*val;
            max_area = max(area, max_area);
            st.pop();

        }

        return max_area;
    }
};
/*
heights = [7,1,7,2,2,4]
st = 0-1, 2-2, 4-2, 5-4  
i=3
idx =5
val=4
area=7
max_area=7
*/