class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> ans(temperatures.size());
        
        for(int i=0;i<temperatures.size();i++){
            if(!st.size() || st.top().first>temperatures[i]){
                st.push({temperatures[i], i});
            } else{
                while(st.size()>0 && st.top().first<temperatures[i]){
                    auto &[temp, idx] = st.top();
                    st.pop();
                    ans[idx] = i-idx;
                }
                st.push({temperatures[i], i});
            }
        }

        while(st.size()){
            auto &[temp, idx] = st.top();
            st.pop();
            ans[idx] = 0;
        }
        
        return ans;
    }
};
/*
    [30,38,30,36,35,40,28]

    st<temp, idx>
    arr=[1,4,1,2,1,,]

    

    
    40,5
    28,6







*/
