class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int preSum = 0;
        map<int, int> mpp;
        mpp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            preSum = (preSum + nums[i] % k + k)%k;
            
            if(mpp.find(preSum % k) != mpp.end()){
                cnt += mpp[preSum % k];
            }
            mpp[preSum % k]++;
        }

        return cnt;
    }
};