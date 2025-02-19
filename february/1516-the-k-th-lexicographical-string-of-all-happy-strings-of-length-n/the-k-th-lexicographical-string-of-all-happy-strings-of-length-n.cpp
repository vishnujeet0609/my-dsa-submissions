class Solution {
public:
    void solve(string& curr, int& n, int& k,string &result, int& counter){
        if(curr.length()==n){
            counter++;
            if(counter==k){
                result=curr;
                return;
            }
            return;
        }
        for(char ch = 'a'; ch<='c';ch++){
            if(!curr.empty() && curr.back()==ch) continue;
            //do
            curr.push_back(ch);
            //explore
            solve(curr,n,k,result,counter);
            //undo
            curr.pop_back();

        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int counter=0;
        solve(curr,n,k,result,counter);
        return result;
    }
};