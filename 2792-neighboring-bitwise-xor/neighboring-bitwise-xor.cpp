class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int XOR=0;
        for(auto &i: derived){
            XOR^=i;
        }
        return XOR==0;
    }
};