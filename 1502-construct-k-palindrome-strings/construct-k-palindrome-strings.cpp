class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n<k) return false;
        if(n==k) return true;
        unordered_map<char,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        int cnt=0;
        for(auto ch: freq){
            if(ch.second & 1==1) cnt++;
        }
        return cnt <=k;
    }
};