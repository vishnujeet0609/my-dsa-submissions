class Solution {
public:
    int partition(vector<vector<int>>& points,int lo, int hi){

        int pivotIdx = lo + rand() % (hi-lo+1);
        swap(points[hi], points[pivotIdx]);
        auto pivot = points[hi];

        int partitionIdx = lo;

        for(int i = lo; i < hi; i++){

            int x1 = points[i][0];
            int y1 = points[i][1];
            int d1 = x1*x1 + y1*y1;

            int x2 = pivot[0];
            int y2 = pivot[1];
            int d2 = x2*x2 + y2*y2;

            if(d1<=d2){
                swap(points[i], points[partitionIdx]);
                partitionIdx++;
            }
        }

        swap(points[hi], points[partitionIdx]);
        return partitionIdx;
    }

    void quickselect(vector<vector<int>>& points,int lo, int hi, int k){
        while(lo<=hi){
            
            int mid = partition(points, lo, hi);

            if(mid == k){
                break;
            }else if(mid < k){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickselect(points, 0, points.size()-1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};