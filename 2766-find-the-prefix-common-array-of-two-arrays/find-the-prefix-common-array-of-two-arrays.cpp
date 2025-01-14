class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int,int>mp;
        vector<int>result;
        int cnt=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                cnt++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                cnt++;
            }
            result.push_back(cnt);

        }
        return result;
    }
};