class Solution {
public:
    int n;
    void dfs(int u,vector<vector<int>>& isConnected,vector<int>&visited){
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v]==1){
                dfs(v,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                count++;
            }
        }
    return count;
    }
};