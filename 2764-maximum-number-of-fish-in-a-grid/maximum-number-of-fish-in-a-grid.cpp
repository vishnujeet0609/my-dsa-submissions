class Dsu{
    vector<int>parent;
    vector<int>size;
public:
    Dsu(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=0;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }

        if(size[x_parent]>size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent]+=size[y_parent];
        }else{
            parent[x_parent] = y_parent;
            size[y_parent]+=size[x_parent];
        }
    }
    void setSize(int x, int fishCount){
        size[x] = fishCount;
    }
    int maxFish(){
        return *max_element(begin(size),end(size));
    }
};

class Solution {
public:
    vector<vector<int>>directions = {{0,-1},{0,1},{-1,0},{1,0}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalCells = m*n;
        Dsu* dsu = new Dsu(totalCells);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    int idx = i*n + j ;  //using this technique we can convert 2d array element into 1d for use in dsu
                    dsu->setSize(idx,grid[i][j]);
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]>0){
                    int idx = i * n + j;
                     for(auto &dir:directions){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_>=0 && j_>=0 && i_<m && j_<n && grid[i_][j_]>0){
                            int idx_ = i_ * n + j_;
                            dsu->Union(idx,idx_);
                        }
                     }
                }
            }
        }
        return dsu->maxFish();
    }
};