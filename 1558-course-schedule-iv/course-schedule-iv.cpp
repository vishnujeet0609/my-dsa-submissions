class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(auto &edge : prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
             q.push(i);
            }
        }
        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &ngbr:adj[node]){
                indegree[ngbr]--;
                mp[ngbr].insert(node);
                for(auto ele: mp[node]){
                    mp[ngbr].insert(ele);
                }
                if(indegree[ngbr]==0){
                    q.push(ngbr);
                }
            }

        }
        vector<bool>result;
        for(auto &q:queries){
            int i = q[0];
            int j = q[1];
            if(mp[j].contains(i)){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }
        return result;
    }
};