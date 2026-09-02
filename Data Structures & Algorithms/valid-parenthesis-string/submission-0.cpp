class Solution {
public:
    bool checkValidString(string s) {
        int count =0;
        stack<pair<char, int>> st;
        vector<int> star;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*' ){
                star.push_back(i);
                continue;
            } else if (s[i] == '('){
                st.push({'(',i});
            } else {
                if(!st.empty()){
                    st.pop();
                } else if(star.size()>0 && star.back()<i){
                    star.pop_back();
                } else{
                    return false;
                }
            }
        }

        if(st.size()==0) return true;

        while(!st.empty()){
            if(star.size() >0 && st.top().second > star.back()){
                return false;
            } else if(star.size()==0){
                return false;
            }

            st.pop();
            star.pop_back();
        }

        return true;
    }
};
