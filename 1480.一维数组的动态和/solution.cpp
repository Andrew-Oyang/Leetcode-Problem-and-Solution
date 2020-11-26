class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
		vector<int> res;
		int nsum = 0;
		if (nums.size() == 0) {
			return nums;
		}
		for (int i=0; i<nums.size();i++) {
			nsum+=nums[i];
			res.push_back(nsum);
		}
		return res;
    }
};
