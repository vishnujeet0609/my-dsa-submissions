class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int[] freq = new int[10001];

        int maxfreq = 0; int maxfreqelem = 0;
        for(int v : barcodes){
            freq[v]++;
            if(freq[v] > maxfreq){
                maxfreq = freq[v];
                maxfreqelem = v;
            }
        }
        int idx = 0;

        for(int i = 0; i <= 10000; i++){
            int elem = i;

            if(i==0){
                elem = maxfreqelem;
            }

            while(freq[elem] > 0){
                barcodes[idx] = elem;

                if(idx + 2 >= barcodes.length){
                    idx = 1;
                }else{
                    idx += 2;
                }

                freq[elem]--;
            }
        }
        return barcodes;
    }
}