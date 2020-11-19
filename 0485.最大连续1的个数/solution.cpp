class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cnt = 0;
		// 需且仅需一次遍历，统计最长连续1的长度，并与历史记录最高值比较
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            }
            if (nums[i] == 0 || i == nums.size() - 1) {
                res = res > cnt? res: cnt;
                cnt = 0;
            } 
        }
        return res;
    }
};
