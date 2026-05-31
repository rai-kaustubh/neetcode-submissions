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
            string x="";
            while(s[i]!='#'){
                x+=s[i];
                i++;
            }
            int _size=stoi(x);
            cout<<_size;
            
            res.push_back(s.substr(i+1, _size));
            i+=_size;
        }
        return res;
    }
};
