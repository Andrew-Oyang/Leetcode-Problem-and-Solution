class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
		// 如何不写烂代码
		// 1. 拒绝冗余
		// 2. 分析问题核心求解的内容，如果不涉及复杂逻辑尽量避免使用
		// 3. 借鉴从简的解题风格和思路
        for (int i = 0; i < timeSeries.size(); i++) {
            res += i == 0 ? duration : min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return res;
    }
};
