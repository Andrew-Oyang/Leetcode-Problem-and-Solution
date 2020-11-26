class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int prev, cnt = 0;
        if (nums.size() <= 2)
            return true;
        prev = nums[0];
        if (nums.size() == 3) {
            if (nums[0]>nums[1] && nums[1]>nums[2]) {
                return false;
            } else
                return true;
        }
        for (int i=0; i<nums.size()-3; i++) {
            if (nums[i]<prev) {
                cnt++;
            }
            prev = nums[i];
            if (cnt>=2)
                return false;
            if (nums[i]<=nums[i+2] && nums[i+2]<=nums[i+3])
                continue;
            if (nums[i]<=nums[i+1] && nums[i+1]<=nums[i+3])
                continue;
            if (nums[i+1]<=nums[i+2] && nums[i+2]<=nums[i+3])
                continue;
            if (nums[i]<=nums[i+1] && nums[i+1]<=nums[i+2])
                continue;
            return false;
        }
        for(int i=nums.size()-3; i < nums.size(); i++) {
            if (nums[i]<prev) {
                cnt++;
            }
            prev = nums[i];
            if (cnt>=2)
                return false;
        }
        return true;
    }
};
