class Solution {
public:
    using state = pair<int, int>; 
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<state>> g(n + 1);
        vector<int> dist(n + 1, 1e9); 
        vector<int> vis(n + 1, 0);
    
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            g[u].push_back({v, w}); 
        }
    
        priority_queue<state> p;
        p.push({-0, k});
        dist[k] = 0;
        
        while(!p.empty()){
            state st = p.top();
            p.pop();
            
            int cur = st.second;
            int d = -st.first; 
            
            if(vis[cur]) continue;
            vis[cur] = 1;
            
            for(auto v : g[cur]){
                if(dist[v.first] > dist[cur] + v.second){
                    dist[v.first] = dist[cur] + v.second;
                    p.push({-dist[v.first], v.first});
                }
            }
        }
        
        int mint = -1e9;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            mint = max(mint, dist[i]);
        }
        
        return mint;
    }
};