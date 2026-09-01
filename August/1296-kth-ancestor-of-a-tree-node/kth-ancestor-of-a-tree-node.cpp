class TreeAncestor {
public:
    vector<vector<int>>par;
    int n;

    TreeAncestor(int n, vector<int>& parent) {
        par.resize(n, vector<int>(20,0));
        this->n = n;
        for(int i =0;i<=19;i++){
            for(int j = 0;j < n;j++){
                if(i==0){
                    par[j][i] = parent[j];
                }else{
                    if(par[j][i-1] != -1)
                        par[j][i] = par[par[j][i-1]][i-1];
                    else{
                        par[j][i] = -1;
                    }
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=19;i>=0;i--){
            if(k & (1<<i)){
                node = par[node][i];
                if(node == -1){
                    break;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */