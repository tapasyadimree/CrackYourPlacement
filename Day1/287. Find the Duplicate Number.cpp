class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];          //1step
            fast = nums[nums[fast]];    //2step
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];          //1step
            fast = nums[fast];          //1step
        }

        return slow;

    }
};