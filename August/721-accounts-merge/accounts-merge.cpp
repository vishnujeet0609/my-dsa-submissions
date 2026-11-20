class Solution {
    class DSU {
        vector<int> parent;
        vector<int> size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY) {
                if(size[rootX] < size[rootY]) {
                    parent[rootX] = rootY;
                    size[rootY] += size[rootX];
                } else {
                    parent[rootY] = rootX;
                    size[rootX] += size[rootY];
                }
            }
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int emailsCount = 0;
        
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                if (emailToIndex.find(account[i]) == emailToIndex.end()) {
                    emailToIndex[account[i]] = emailsCount++;
                    emailToName[account[i]] = name;
                }
            }
        }
        
        DSU dsu(emailsCount);
        for (const auto& account : accounts) {
            int firstEmailIndex = emailToIndex[account[1]];
            for (int i = 2; i < account.size(); i++) {
                dsu.unite(firstEmailIndex, emailToIndex[account[i]]);
            }
        }
        
        unordered_map<int, vector<string>> components;
        for (const auto& pair : emailToIndex) {
            string email = pair.first;
            int index = pair.second;
            int root = dsu.find(index);
            components[root].push_back(email);
        }

        vector<vector<string>> mergedAccounts;
        for (auto& component : components) {
            vector<string>& emails = component.second;
            sort(emails.begin(), emails.end());
            
            vector<string> mergedAccount;
            mergedAccount.push_back(emailToName[emails[0]]); 
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            
            mergedAccounts.push_back(mergedAccount);
        }
        
        return mergedAccounts;
    }
};