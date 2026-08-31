class Solution {
public:
    int n;
    vector<string>result;

    bool isValid(string t){
        if(t[0] == '0'){
            return false;
        }
        int num = stoi(t);
        return num<=255;
    }

    void rec(string& s, int idx,int part, string cur){

        if(idx == n && part == 4){
            cur.pop_back();
            result.push_back(cur);
            return;
        }


        if(idx+1 <= n){
            rec(s, idx+1, part+1, cur + s.substr(idx, 1) + ".");
        }
        if(idx+2 <= n && isValid(s.substr(idx, 2))){
            rec(s, idx+2, part+1, cur + s.substr(idx, 2) + ".");
        }
        if(idx+3 <= n && isValid(s.substr(idx, 3))){
            rec(s, idx+3, part+1, cur + s.substr(idx, 3) + ".");
        }

    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();

        if(n<4 && n > 12){
            return {};
        }

        string cur = "";
        int part = 0;

        rec(s, 0, part, cur);
        return result;
        
    }
};