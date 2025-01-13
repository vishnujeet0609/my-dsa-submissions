class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n<=2) return n;
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }
        int count = 0;
        for(auto i:freq){
            if(i.second %2==0){
                count+=2;
            }else{
                count+=1;
            }
        }
        return count;
    }
};