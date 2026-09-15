class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        int top = 0, bottom = m.size()-1,left = 0, right = m[0].size()-1;

        while(top<=bottom && left<=right){
            for(int c = left;c<=right;c++){
                ans.push_back(m[top][c]);
            }
            top++;

            for(int r=top;r<=bottom;r++){
                ans.push_back(m[r][right]);
            }
            right--;

            if(top<=bottom){
                for(int c=right;c>=left;c--){
                    ans.push_back(m[bottom][c]);
                }
                bottom--;
            }

            if(left<=right){
                for(int r=bottom;r>=top;r--){
                    ans.push_back(m[r][left]);
                }

                left++;
            }

        }

        return ans;
    }
};
