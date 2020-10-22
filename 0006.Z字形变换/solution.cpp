class Solution {
public:
    string convert(string s, int numRows) {
		vector<string> slines(numRows);
        string res;
        int r, len = s.length();

        if (numRows <= 1) {
            return s;
        }
        for (int i = 0; i < len; i++) {
            r = i % (2 * numRows - 2);
            if(r <= numRows - 1) 
                slines[r] += s[i];
            else
                slines[2 * numRows -2 - r] += s[i];
        }
        for (int i = 0; i < numRows; i++) {
            res += slines[i];
        }
        return res;
    }
};
