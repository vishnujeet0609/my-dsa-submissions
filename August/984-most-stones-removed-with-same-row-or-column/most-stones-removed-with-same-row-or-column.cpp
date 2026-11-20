class Solution {
    unordered_map<int, int> parent;
    int connectedComponents = 0;

    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            connectedComponents++;
        }
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;
            connectedComponents--;
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        for (const auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001; 
            
            unite(row, col);
        }
        return stones.size() - connectedComponents;
    }
};