class Solution {
public:

    int check(int row, int col, vector<int>&cur){
        for(int pr = 0;pr<row;pr++){
            int pc = cur[pr];
            if((pc == col)  || (abs(pr-row) == abs(pc-col))){
                return 0;
            }
        }
        return 1;
    }

    void rec(int level, vector<int>&cur, vector<vector<int>>&correctPos, int n){
        if(level>=n){
            correctPos.push_back(cur);
            return;
        }

        for(int i = 0 ; i<n;i++){
            if(check(level, i,cur)){
                cur[level] = i;
                rec(level+1, cur, correctPos, n);
                cur[level] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>correctPos;
        vector<int>cur(n,-1);

        rec(0, cur, correctPos, n);

        vector<vector<string>>ans;
        for(int i = 0; i<correctPos.size();i++){
            vector<string>temp(n, string(n,'.'));
            for(int j = 0;j<n;j++){
                if(correctPos[i][j] != -1){
                    temp[j][correctPos[i][j]] = 'Q';
                }
            }
            ans.push_back(temp);
        }
    return ans;
    }
};