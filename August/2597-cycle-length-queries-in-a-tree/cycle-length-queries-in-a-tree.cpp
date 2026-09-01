class Solution {
public:
  
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            int cycleLen = 1; 
            
            while (u != v) {
                if (u > v) {
                    u /= 2;  
                } else {
                    v /= 2; 
                }
                cycleLen++;
            }
            
            ans.push_back(cycleLen);
        }
        
        return ans;
    }
};