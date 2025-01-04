class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int count=0;
        unordered_map<char,int>firstOcc;
         unordered_map<char,int>lastOcc;
        for(int i=0;i<n;i++){
            if(firstOcc.find(s[i])==firstOcc.end()){
                firstOcc[s[i]]=i;
            }
            lastOcc[s[i]]=i;
        }
        for(auto &i: firstOcc){
            int first = i.second;
            int last = lastOcc[i.first];
            if(first==last) continue;
            set<char>set1;
            for(int j=first+1;j<last;j++){
                set1.insert(s[j]);
            }
            count+=set1.size();
        }

       return count; 

    }
};