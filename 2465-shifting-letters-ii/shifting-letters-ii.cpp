class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>diff(n,0);
        for(auto shift:shifts)
        {
            if(shift[2]==0){
                diff[shift[0]]--;
                if((shift[1]+1)<n){
                    diff[shift[1]+1]++;
                }
            }else{
                diff[shift[0]]++;
                if((shift[1]+1)<n){
                    diff[shift[1]+1]--;
                }
            }
        }
        string ans(n,' ');
        int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+diff[i])%26;
            if(sum<0)sum+=26;
            char ch = (char)('a'+(((s[i]-'a')+sum)%26));
            ans[i]=ch;
        }
        return ans;
    }
};