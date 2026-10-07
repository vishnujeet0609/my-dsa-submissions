class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int i = 0;
        int j = 1;
        int count = 0;

        while (j < n) {

            int ce = intervals[i][1];

            int ns = intervals[j][0];
            int ne = intervals[j][1];

            if (ce <= ns) {
                i = j;
            } else if (ce <= ne) {
                count++;
            } else if (ce > ne) {
                i = j;
                count++;
            }
            j++;
        }
        return count;
    }
};