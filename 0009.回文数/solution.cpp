class Solution {
public:
    bool isPalindrome(int x) {
        long long re = 0, y = x;
        if(x < 0)
            return false;
        else {
            while (x != 0) {
                re = re * 10 + x %10;
                x = x / 10;
            }
        }
        return (re==y)?true:false;
    }
};
