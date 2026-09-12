class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>arr(26,0);

        int n = s.length();
        int m = p.length();

        for(auto v : p){
            arr[v-'a']++;
        }
        int i = 0;
        int j = 0;
        vector<int>result;
        while(i<n){
                while(j<n && (j-i+1 <= m)){
                    arr[s[j]-'a']--;
                    j++;
                }
                if(arr == vector<int>(26,0)){
                    result.push_back(i);
                }
                arr[s[i]-'a']++;
                i++;
        }
        return result;
    }
};