class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adj[u].push_back({v, price});
        }
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
      
        queue<pair<int, int>> q;
        q.push({src, 0});
      
        int stops = 0;
        
        while(!q.empty() && stops <= k) {
            int size = q.size();
         
            while(size--) {
                auto ele = q.front();
                q.pop();
                
                int node = ele.first;
                int cost = ele.second;
          
                for(auto& neighbor : adj[node]){
                    int nextNode = neighbor.first;
                    int price = neighbor.second;
                
                    if(cost + price < dist[nextNode]){
                        dist[nextNode] = cost + price;
                        q.push({nextNode, dist[nextNode]});
                    }
                }
            }
            stops++;
        }
    
        if(dist[dst] == 1e9) {
            return -1;
        }
        
        return dist[dst];
    }
};