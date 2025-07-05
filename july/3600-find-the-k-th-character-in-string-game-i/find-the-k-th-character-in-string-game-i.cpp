//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);

        return 'a' + shift;
    }
};