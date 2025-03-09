class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int>isplaced(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && isplaced[j]==0){
                    isplaced[j] = 1;
                    break;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(isplaced[i]==0){
                cnt++;
            }
        }
        return cnt;
    }
};