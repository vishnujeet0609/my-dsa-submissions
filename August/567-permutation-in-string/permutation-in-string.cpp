class Solution {
public:

    bool check(vector<int>&freq1, vector<int>&freq2){
        for(int i=0 ; i<26 ; i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
       return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0; i<n1; i++){
            freq1[s1[i]-'a']++;
        }

        int tail = 0;
        int head = 0;

        while(tail<(n2-n1+1)){
            while(head<n2 && (head-tail + 1)<=n1){
                freq2[s2[head] - 'a']++;
                head++;
            }
            if(check(freq1,freq2)){
                return true;
            }
            freq2[s2[tail]-'a']--;
            tail++;
        }
        return false;
    }
};