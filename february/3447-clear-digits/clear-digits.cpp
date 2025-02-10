class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();

        int i =0;
        int j=0;

        while(n--){
            if(isdigit(s[i])){
                j--;
            }else{
                s[j]=s[i];
                j++;
            }
            i++;
        }
        s.resize(j);
        return s;
    }
};