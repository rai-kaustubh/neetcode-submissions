class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto s: strs){
            str+=to_string(s.size())+"#"+s;
        }

        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i=0,j=0;
        while(i<s.size()){
            j=i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, len);
            ans.push_back(str);
            i=j+len+1;
        }

        return ans;
    }
};
