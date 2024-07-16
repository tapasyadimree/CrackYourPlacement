class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int preSum = 0;
        map<int, int> mpp;
        mpp[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            if(mpp.find(remove) != mpp.end()){
                cnt += mpp[remove];
            }
            mpp[preSum]++;
        }

        return cnt;
    }
};