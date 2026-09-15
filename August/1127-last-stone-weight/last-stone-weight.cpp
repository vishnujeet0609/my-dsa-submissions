class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;

        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            if(pq.size() == 1){
                break;
            }
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            if(num1 != num2){
                pq.push(num1-num2);
            }
        }
        return pq.size()>0 ? pq.top() : 0;
    }
};