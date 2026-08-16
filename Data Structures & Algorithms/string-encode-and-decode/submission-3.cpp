class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string str: strs){
            s+=to_string(str.size())+'#'+str;
        }
        // cout<<s;
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(j<s.size() && s[j]!='#'){
                j++;
            }

            string sz = (s.substr(i, j-i));
            cout<<sz;
            int size =stoi(sz);
            j++;   
            res.push_back(s.substr(j, size));
            i=j+size;
        }

        return res;
    }
};
