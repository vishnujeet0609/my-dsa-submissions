class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
     
        vector<int> dist(n, 1e9);
        queue<int> q;
        
        dist[0] = 0;
        q.push(0);
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            
            for(auto v : adj[ele]){
                if(dist[v] > dist[ele] + 1){
                    dist[v] = dist[ele] + 1;
                    q.push(v);
                }
            }
        }
        
        int maxTime = 0;
        for(int i = 1; i < n; i++){

            int rt = 2 * dist[i]; 
            
            int last_send = ((rt - 1) / patience[i]) * patience[i];
            
            int time_arrived = last_send + rt;
            
            maxTime = max(maxTime, time_arrived);
        }
        return maxTime + 1;
    }
};