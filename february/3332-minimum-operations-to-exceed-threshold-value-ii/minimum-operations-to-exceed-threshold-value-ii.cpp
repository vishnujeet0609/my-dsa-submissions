class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>>pq(begin(nums),end(nums));
        int count=0;
        while(!pq.empty() && pq.top()<k){
            long smallest1 =pq.top();
            pq.pop();
            long smallest2 = pq.top();
            pq.pop();
            pq.push(smallest1*2 + smallest2);
            count++;
        }
        return count;
    }
};