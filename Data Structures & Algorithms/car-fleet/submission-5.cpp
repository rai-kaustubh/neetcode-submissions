class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> time;
        vector<pair<int, int>> v;
        for(int i=0;i<speed.size();i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        
        for(int i=0;i<v.size();i++){
            time.push_back((double)(target-v[i].first)/v[i].second);
        }

        stack<double> st;
        for(int i=time.size()-1; i>=0;i--){
            if(!st.size()){
                st.push(time[i]);
                continue;
            }

            while(st.size()>0 && time[i]>st.top()){
                st.push(time[i]);
                // st.pop();
            }
        }
        return st.size();
    }
};
/*
    target = 10, position = [4,1,0,7], speed = [2,2,1,1]
    t=d/s
    v= [{0,1}, {1,2}, {4,2}, {7,1}]
    t =[10, 4.5, 3, 3]

    st = 3, 4.5 

*/
