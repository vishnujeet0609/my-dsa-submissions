class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        priority_queue<vector<int>>pq;

        for(auto point : points){
            
            int x = point[0];
            int y = point[1];

            pq.push({x*x + y*y, x, y});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];

            pq.pop();

            ans.push_back({x,y});
        }
        return ans;
    }
};