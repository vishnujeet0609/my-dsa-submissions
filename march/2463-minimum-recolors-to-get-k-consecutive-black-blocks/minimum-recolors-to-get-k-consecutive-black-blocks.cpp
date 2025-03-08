class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i = 0;
        int j = i+k-1;
        vector<int>prefixwhitecnt(n);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(blocks[i]=='W'){
                cnt++;
                
            }
            prefixwhitecnt[i] = cnt;
        }
        int minblockstorecolor = INT_MAX;
        while(i<n && j<n){
            int blockstorecolor = prefixwhitecnt[j];
            if(i>0)
                blockstorecolor = prefixwhitecnt[j]-prefixwhitecnt[i-1];
            minblockstorecolor = min(minblockstorecolor,blockstorecolor);
            i++;
            j++;
        }
        return minblockstorecolor;
    }
};