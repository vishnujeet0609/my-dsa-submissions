class Solution {
    public int jump(int[] nums) {
        int jump = 0;

        if (nums.length == 1)
            return 0;

        int farthest = 0;
        int lastidx = 0;

        for (int i = 0; i < nums.length; i++) {
            farthest = Math.max(farthest, i + nums[i]);

            if (i == lastidx) {
                lastidx = farthest;
                jump++;

                if (farthest >= nums.length - 1) {
                    return jump;
                }
            }

        }
        return jump;
    }
}