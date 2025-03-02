class Solution {
public:
    int n,m,l;
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool find(vector<vector<char>>& board, int i,int j,int idx, string& word){
        if(idx >= l){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j]='$';
        for(vector<int>& dir: directions){
            int i_ =  i + dir[0];
            int j_ =  j + dir[1];
            if(find(board,i_,j_,idx+1,word)){
                return true;
            }

        }
        board[i][j] = temp;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if(m*n < l){
            return false;
        }
        for(int i = 0;i<m;i++){
            for(int j=0; j<n;j++){
                if(board[i][j]==word[0] && find(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};