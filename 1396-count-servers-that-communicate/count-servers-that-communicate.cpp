class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>colCountServer(n,0);
        vector<int>rowSingleServerCol(m,-1);
        int resultServers=0;
        for(int i=0;i<m;i++){
            int countServer=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    countServer+=1;
                    colCountServer[j]+=1;
                    rowSingleServerCol[i]=j;
                }
            }
            if(countServer > 1){
                resultServers+=countServer;
                rowSingleServerCol[i]=-1;

            }
        }
        for(int i=0;i<m;i++){
            if(rowSingleServerCol[i]!=-1 ){
               int col =rowSingleServerCol[i];
                if(colCountServer[col]>1){
                    resultServers+=1;
                }
                    
            }
        }
    return resultServers;
    }
};