class Solution {
    class RowInfo{
        int strength = 0;
        int index;
    }
    public int[] kWeakestRows(int[][] mat, int k) {
        int n = mat.length;
        int m = mat[0].length;
        
        PriorityQueue<RowInfo> pq = new PriorityQueue<>((a,b)->{
            if(a.strength != b.strength){
                return Integer.compare(a.strength, b.strength);
            }else{
                return Integer.compare(a.index, b.index);
            }
        });

        for(int i = 0; i<n ;i++){
            RowInfo info  = new RowInfo();
            info.index = i;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1)
                    info.strength++;
            }
            pq.offer(info);
        }

        int[] ans = new int[k];
        for(int i = 0; i<k; i++){
            ans[i] = pq.poll().index;
        }
        return ans;
    }
}