class Solution {
public:
    bool isCycleDfs(int u, vector<vector<int>>& graph, vector<int>&visited,vector<int>&inRecursion){
        visited[u]=1;
        inRecursion[u]=1;
        for(auto v: graph[u]){
            if(!visited[v] && isCycleDfs(v,graph,visited,inRecursion)){
                return true;
            }else if(inRecursion[v]==1){
                return true;
            }
        }
        inRecursion[u]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int>inRecursion(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                isCycleDfs(i,graph,visited,inRecursion);
            }
        }
        vector<int>safeNodes;
        for(int i =0;i<n;i++){
            if(inRecursion[i]==0){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};