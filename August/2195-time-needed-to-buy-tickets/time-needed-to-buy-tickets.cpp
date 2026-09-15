class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();

       queue<pair<int,int>>q;

       for(int i = 0; i<n;i++){
        q.push({i,tickets[i]});
       }

       int time = 0;
       while(!q.empty()){
         auto temp = q.front();
         q.pop();
         temp.second = temp.second-1;
         time++;
         if(temp.first == k && temp.second == 0){
            break;
         }
         if(temp.second != 0)
            q.push(temp);
       }
       return time;
    }
};