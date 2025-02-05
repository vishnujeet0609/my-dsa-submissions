class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int diff=0;
        int firstIndex=0;
        int secondIndex=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff++;
                if(diff>2) return false;
                else if(diff==1){
                    firstIndex=i;
                }else{
                    secondIndex=i;
                }
            }
        }
        swap(s1[firstIndex],s1[secondIndex]);
        return s1==s2;    }
};