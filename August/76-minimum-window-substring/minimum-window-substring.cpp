class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n<m) return "";

        vector<int>freq(128,0);
        for(auto v : t){
            freq[v]++;
        }
        int startIdx = -1;
        int head = -1;
        int tail = 0;
        int minLen = 1e9;
        int match = 0;

        while(tail<n){
            while(head+1 < n && match < m){
                head++;
                freq[s[head]]--;
                if(freq[s[head]]>=0){
                    match++;
                }
            }

            if(match == m){
                if(minLen > head-tail+1){
                    minLen = head-tail+1;
                    startIdx = tail;
                }
            }

            if(tail > head){
                tail++;
                head = tail-1;
            }else{
                freq[s[tail]]++;
                if(freq[s[tail]] > 0){
                    match--;
                }
                tail++;
            }
        }
        if(startIdx == -1) return "";
        return s.substr(startIdx, minLen);
    }
};