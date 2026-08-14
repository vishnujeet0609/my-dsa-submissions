class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        long long number = 0;

        while(i<n && s[i] == ' '){
            i++;
        }
        if(i<n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        while(i<n){
            if(s[i] >='0' && s[i]<='9'){
                if(number <= INT_MAX){
                    number = number * 10 + s[i] - '0';
                    i++;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        number = number * sign;
        if(number < INT_MIN){
            return INT_MIN;
        }
        if(number > INT_MAX){
            return INT_MAX;
        }

        return number;
    }
};