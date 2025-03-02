class Solution {
public:
    int n,m;
    int emptycells;
    int result = 0;
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    void find(int i, int j, int currcells, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1){
            return;
        }
        if(grid[i][j]==2){
            if(currcells==emptycells)
                result++;
            return;
        }
        grid[i][j]=-1;
        for(auto& dir: directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            find(i_,j_,currcells+1,grid);
        }
        grid[i][j]=0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int start_x;
        int start_y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    emptycells++;
                }
                if(grid[i][j]==1){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        emptycells+=1;
        int currcells = 0;
        find(start_x,start_y,currcells,grid);
        return result;

    }
};