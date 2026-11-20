class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
  
    bool check(vector<vector<int>> &grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        
        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
            return true;
        }
        return false;
    }
  
    vector<vector<int>> getNeighbours(vector<vector<int>> &grid, vector<int>& s){
        vector<vector<int>> ngb;
        
        for(int i = 0; i < 4; i++){
            int x_ = s[0] + dx[i];
            int y_ = s[1] + dy[i];
            
            if(check(grid, x_, y_)){
                ngb.push_back({x_, y_});
            }
        }
        
        return ngb;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int freshOranges = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        
        if (freshOranges == 0) return 0;
        
        int minutesPassed = 0;
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            
            for(auto v : getNeighbours(grid, ele)){
                if(dist[v[0]][v[1]] > dist[ele[0]][ele[1]] + 1){
                    dist[v[0]][v[1]] = dist[ele[0]][ele[1]] + 1;
                    
                    grid[v[0]][v[1]] = 2; 
                    freshOranges--;

                    minutesPassed = max(minutesPassed, dist[v[0]][v[1]]);
                    
                    q.push(v);
                }
            }
        }
     
        if (freshOranges > 0) {
            return -1;
        }
        
        return minutesPassed;
    }
};