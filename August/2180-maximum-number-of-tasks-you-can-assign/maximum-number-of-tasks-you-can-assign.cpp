class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int>mt(workers.begin(), workers.begin() + mid);

        for(int i = mid-1; i>=0 ; i--){
            int required = tasks[i];

            auto maxStrengthWorkerItr = prev(mt.end());

            if(*maxStrengthWorkerItr >= required){
                mt.erase(maxStrengthWorkerItr);
            }else if(pillsUsed >= pills){
                return false;
            }else{
                auto minstrengthWorkerItr = mt.lower_bound(required - strength);
                if(minstrengthWorkerItr == mt.end()){
                    return false;
                }else{
                    mt.erase(minstrengthWorkerItr );
                    pillsUsed++;
                }
            }
        
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers), [&](int a, int b)-> bool {return a > b ;});

        int lo = 0;
        int hi = min(n,m);
        int ans = 0;
        while(lo<=hi){
            int mid  = lo + (hi - lo)/2;

            if(check(tasks, workers, pills, strength, mid)){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid-1;
            }
        }

        return ans;
    }
};