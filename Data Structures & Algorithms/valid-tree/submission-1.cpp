class Solution {
public:
    vector<int> rank;
    vector<int> root;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        for(int i=0;i<n;i++){
            rank.push_back(1);
            root.push_back(i);
        }

        for(auto edge: edges){
            if(!_union(edge[0],edge[1])){
                return false;
            }
        }

        return true;
    }

    int find(int x){
        if(root[x]==x){
            return x;
        }
        return root[x]=find(root[x]);
    }

    bool _union(int x, int y){
        auto rootX = find(x);
        auto rootY = find(y);

        if(rootX==rootY) return false;

        if(rank[rootX]>rank[rootY]){
            root[rootY]=rootX;
        } else if(rank[rootY]>rank[rootX]){
            root[rootX]=rootY;
        } else{
            root[rootY]=rootX;
            rank[rootX]++;
        }

        return true;
    }


};
