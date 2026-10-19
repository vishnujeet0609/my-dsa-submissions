class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int>mp;

        for(auto word : words){
            mp[word]++;
        }

        auto cmp = [&](auto a, auto b)-> bool{
            if(a.first != b.first){
                return a.first > b.first;
            }
            return a.second < b.second;
        };

        priority_queue<pair<int, string>, vector<pair<int,string>>, decltype(cmp)>pq(cmp);

        for(auto ele : mp){
            pq.push({ele.second, ele.first});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};