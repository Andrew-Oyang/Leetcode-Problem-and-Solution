class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;
        int flag = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]==INT_MIN) flag = 1;
            if (nums[i] == first || nums[i] == second) continue;
            if(first < nums[i]) {
                if (first > INT_MIN) {
                    third = second;
                    second = first;
                }
                first = nums[i];
                continue;
            }
            if(second < nums[i]) {
                if (second > INT_MIN) third = second;
                second = nums[i];
                continue;
            }
            if (third < nums[i]) {
                third = nums[i];
            }
        }
        if (flag==1 && second != INT_MIN)
            return INT_MIN;
        if (nums.size() < 3)
            return first;
        return third == INT_MIN ? first:third;
    }
};
