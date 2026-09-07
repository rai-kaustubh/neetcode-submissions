class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        dfs(0, partition, s);
        return ans;
    }

    void dfs(int j, vector<string>& partition, string& s){
        if(j==s.size()){
            ans.push_back(partition);
            return;
        }

        for(int i=j;i<s.size();i++){
            if(isPali(s, j, i)){
                partition.push_back(s.substr(j, i-j+1));
                dfs(i+1, partition, s);
                partition.pop_back();
            }
        }

        return;
    }

    bool isPali(string& s, int l ,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
