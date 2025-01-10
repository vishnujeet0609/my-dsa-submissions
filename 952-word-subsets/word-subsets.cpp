class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> freq;
        for (auto word : words2) {
            map<char, int> temp;
            for (int i = 0; i < word.length(); i++) {
                temp[word[i]]++;
            }
            for (auto i : temp) {
                if (freq.find(i.first) != freq.end()) {
                    freq[i.first] = max(freq[i.first], i.second);
                } else {
                    freq[i.first] = i.second;
                }
            }
        }
        vector<string>res;
        for(auto word:words1){
            map<char,int>temp;
             for (int i = 0; i < word.length(); i++) {
                temp[word[i]]++;
            }
            bool flag=true;
            for(auto ele:freq){
                if(temp.find(ele.first)==temp.end() || temp[ele.first]<ele.second){
                    flag=false;
                    break;
                }
            }
            if(flag){
                res.push_back(word);
            }
        }
        return res;
    }
};