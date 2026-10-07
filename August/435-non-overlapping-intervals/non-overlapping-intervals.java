import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {

        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        int n = intervals.length;
        int j = 1;
        int count = 0;

        int[] prev_interval = intervals[0];

        while (j < n) {
            int pe = prev_interval[1];
            
            int cs = intervals[j][0];
            int ce = intervals[j][1]; 

            if (pe <= cs) {
                prev_interval = intervals[j];
            } else {
                count++;
            }

            j++;
        }

        return count;
    }
}