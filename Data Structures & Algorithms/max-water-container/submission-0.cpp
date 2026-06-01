class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int ans=INT_MIN;
        
        while(l<r){
            int curr=(r-l)*min(heights[l], heights[r]);
            ans = max(curr, ans);

            if(heights[l]<heights[r]){
                l++;
            }else r--;
        }

        return ans;
    }
};
