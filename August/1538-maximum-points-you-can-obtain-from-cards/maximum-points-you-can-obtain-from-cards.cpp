class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int>pref(n,0);
        for(int i=0;i<n; i++){
            if(i==0){
                pref[i] = cardPoints[i];
            }else{
                pref[i]+= pref[i-1] + cardPoints[i];
            }
        }


        int tail = 0;
        int head = n-1;
        int score = 0;

        while(tail<=head){
            if(k<=0){
                break;
            }
            
            int tailKSum = tail==0 ? pref[tail+k-1] : pref[tail+k-1] - pref[tail-1];
            int headKSum = head-k < 0 ? pref[head] : pref[head]- pref[head-k];

            if(tailKSum <= headKSum){
                score+=cardPoints[head];
                head--;
                k--;
            }else{
               score+=cardPoints[tail];
                tail++;
                k--;  
            }
        }
        return score;
    }
};