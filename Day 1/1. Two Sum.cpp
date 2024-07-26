class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int req = target - nums[i];
            if(mpp.find(req) != mpp.end()){
                ans = {mpp[req], i};
                break;
            }
            mpp[nums[i]] = i;
        }

        return ans;
    }
};