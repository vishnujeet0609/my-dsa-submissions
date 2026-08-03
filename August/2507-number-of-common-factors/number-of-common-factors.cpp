class Solution {
public:
    map<int,int> mp;
    void calculateFreq(int a){
        for(int i=1; i*i <= a;i++){
            if(a%i==0){
                mp[i]++;
                if(i*i!=a){
                    mp[a/i]++;
                }
            }
        }
    }
    int commonFactors(int a, int b) {
        calculateFreq(a);
        calculateFreq(b);

        int cnt = 0;
        for(auto v : mp){
            if(v.second >=2){
                cnt++;
            }
        }
        return cnt;
    }
};