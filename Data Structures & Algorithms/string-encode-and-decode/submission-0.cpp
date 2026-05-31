class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string s: strs){
            res+=to_string(s.size())+'#'+s;
        }
        cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        int currSize=0;
        vector<string> res;
        for(int i=0;i<s.length();i++){
            int _size=s[i]-'0';
            res.push_back(s.substr(i+2, _size));
            i+=_size+1;
        }
        return res;
    }
};
