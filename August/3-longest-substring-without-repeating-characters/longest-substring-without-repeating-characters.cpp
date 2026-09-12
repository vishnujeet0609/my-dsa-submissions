class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>seen;
        int n = s.length();

        int tail = 0;
        int head = 0;

        int ans = 0;
        while(tail < n){
            while(head < n && !seen[s[head]]){
                seen[s[head]]++;
                head++;
                
            }
            ans = max(ans,head-tail);
            seen[s[tail]]--;
            if(seen[s[tail]] == 0){
                seen.erase(s[tail]);
            }
            tail++;

        }
        return ans;
    }
};