class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        int i = 0;
        int j = m-1;
        long long mini = INT_MAX;
        
        while(j < n){
            long long diff = a[j] - a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        
        return mini;
    }   
};