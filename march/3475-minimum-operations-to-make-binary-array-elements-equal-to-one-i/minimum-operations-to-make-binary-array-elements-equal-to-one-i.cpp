class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        int currflipCountfori = 0;
        deque<int>dq;
        for(int i = 0;i<n;i++){
            if(i>=3){
                currflipCountfori-=dq.front();
                dq.pop_front();
            }
            if(currflipCountfori%2==nums[i]){
                if(i+3>n){
                    return -1;
                }
                currflipCountfori++;
                flips++;
                dq.push_back(1);
            }else{
                dq.push_back(0);
            }
        }
        return flips;
    }
};