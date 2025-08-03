class Solution {
public:
    vector<int> getRow(int line) {
        int prev = 1;
        vector<int> temp{1};
        for (int i = 1; i < line + 1; i++) {
            int curr = ((line - i + 1) * prev) / i;
            temp.push_back(curr);
            prev = curr;
        }
        return temp;
    }

    vector<vector<int>> generate(int line) {
        vector<vector<int>> result;
        result.push_back({1});
        if (line == 1) {
            return result;
        }

        for (int lineNo = 1; lineNo < line; lineNo++) {
            result.push_back(getRow(lineNo));
        }

        return result;
    }
};