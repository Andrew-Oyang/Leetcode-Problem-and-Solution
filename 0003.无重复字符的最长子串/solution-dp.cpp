class Solution {
public:
	/* Using Dynamic Planning to solve this problem requires the coder to focus on 2 things:
	 *	1. State Transition Equation (which is, HOW to transit from dp[i - 1] to dp[i])
	 *	2. (Whenever we move to a new point, it means we need to compare a new character with all non-repeated-characters in front of it, and we compare this length with current dp[i-1] value. If this value > dp[i-1], then dp[i] = dp[i-1]+1; Else then dp[i] = dp[i-1]. The reason why dp[i] = dp[i-1] + 1 is that we only move one character per decision). Therefore, update the farthest character (process-with-no-duplicated charaters) from current 'i'.
	 *
	 *	Consider bound value is also very important in dp solutions. Here are what we got:
	 *
	 **/
    int lengthOfLongestSubstring(string s) {
		// dynamic planning array, which record the length of 'the longest substring' so far
		vector<int> dp;
		// st = start position. which represents for the start index of 'the longest substring' so far
		// rf = repeat flag. which represents for a repeated s[j] (of s[i]) is found. 
		// if s[i] == s[j] (st <= j <= i-1), then rf = 1; Else rf = 0.
		int st = 0, rf = 0;
        if (s.length() == 1 || s.length() == 0)
            return s.length();
        // dp[0] = 1;
        dp.push_back(1);
        for (int i = 1; i < s.length(); i++) {
			// find if there is repeatded element of s[i], from (s[j]=) s[st] to s[i-1];
            for (int j = i - 1; j >= st; j--) {
                if (s[i]==s[j]) {
					// if element repeated,
					// 1. Update st value;
                    st = j + 1;
					// 2. dp[i] = dp[i-1];
                    dp.push_back(dp[i - 1]);
					// 3. set repeat flag to 1;
                    rf = 1;
                    break;
                }
				// if there is no repeated element, set repeat flag to 0
                if (j == st)
                    rf = 0;
            }
			// if rf == 1, then go directly to next loop of 'i'
            if (rf == 0) {
				// judge if from st to i is longer than older 'longest substring length'
				// 1. if so, update dp[i] = dp[i-1] + 1;
                if (i - st + 1 > dp[i - 1]) {
                     dp.push_back(dp[i - 1] + 1);
				// 2. if not, update dp[i] = dp[i-1];
                } else {
                     dp.push_back(dp[i - 1]);
                }
            }
        }
		// return last element of dp array, which is the recorded longest substring length of 's'
        return dp[s.length() - 1];
    }
};
