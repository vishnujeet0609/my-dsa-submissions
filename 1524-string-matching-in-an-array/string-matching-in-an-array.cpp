class Solution {
public:
    bool isSubstring(string subs, string word) {
       
        for (int j = 0; j < word.size(); j++) {
            bool found = true;
            int k = j;
            int i = 0;
            while (i < subs.size()) {
                if (k >= word.size() || subs[i] != word[k]) {
                    found = false;
                    break;
                }
                i++;
                k++;
            }
            if(found==true) return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        vector<string> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (isSubstring(words[i], words[j])) {
                    temp.push_back(words[i]);
                    break;
                }
            }
        }
        return temp;
    }
};