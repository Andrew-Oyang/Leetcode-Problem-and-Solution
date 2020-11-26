class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A == B) {
            string C; 
            for (int i = 0; i < A.size(); i ++) {
                if(C.find(A[i]) != -1) return true;
                else C += A[i];
            }
            return false;
        }
        else {
            int i = 0, j = 0;
            while (A[i] == B[i]) i ++;
            j = i, i ++;
            while (A[i] == B[i]) i ++;
            swap(A[i],A[j]);
			return (A==B)?true:false;
        }
    }
};
