class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int>freq(26,0);

        int tail=0;
        int head = -1;
        int maxfreq = 0;
        int ans = 0;

        while(tail<n){
            while(head+1 < n){
                freq[s[head+1]-'A']++;

                maxfreq = max(maxfreq, freq[s[head+1]-'A']);

                if(((head-tail+2) - maxfreq) <= k){
                    head++;
                }else{
                    freq[s[head+1]-'A']--;
                    break;
                }
            }
            ans = max(ans, head-tail+1);

            if(tail>head){
                tail++;
                head = tail-1;
            }else{
                freq[s[tail] - 'A']--;
                tail++;
            }
        }
        return ans;
    }
};