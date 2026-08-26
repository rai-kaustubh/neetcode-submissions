class Solution {
public:
    vector<vector<int>> ans;
    vector<int> rank, root;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                cout<<"hello"<<endl;
        for(int i=0;i<=edges.size();i++){
            rank.push_back(1);
            root.push_back(i);
        }
        for(auto edge: edges){
            if(!_union(edge[0], edge[1])){
                ans.push_back(edge);
            }
        }

        return ans.back();
    }

    int find(int x){
        if(x==root[x]){
            return x;
        }
        return root[x]=find(root[x]);
    }

    bool _union(int x, int y){
        auto rootX = find(x);
        auto rootY = find(y);

        if(rootX == rootY){
            return false;
        }

        if(rank[rootX]>rank[rootY]){
            root[rootY]=rootX;
        } else if(rank[rootY]>rank[rootX]){
            root[rootX]=rootY;
        } else {
            root[rootY]=rootX;
            rank[rootX]++;
        }

        return true;
    }
};
