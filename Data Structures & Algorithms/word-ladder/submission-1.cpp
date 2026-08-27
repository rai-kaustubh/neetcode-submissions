class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // change entire wordList into set<strings>
        unordered_set<string> _set(wordList.begin(), wordList.end());
        if(_set.count(endWord)==0) return 0;

        queue<string> q;
        q.push(beginWord);

        int level=0;
        while(!q.empty()){
            level++;
            int size = q.size();
                        
            while(size--){
                auto top = q.front();
                q.pop();
                
                if (top == endWord){
                    return level;
                } 

                for(int i=0;i<top.size();i++){
                    char original = top[i];
                    for(char c='a';c<='z';c++){
                        if(c==original) continue;
                        top[i]=c;
                        if(_set.count(top)!=0){
                            q.push(top);
                            _set.erase(top);
                        }
                    }
                    top[i]=original;
                }
            }
        }

        return 0;
    }
};
