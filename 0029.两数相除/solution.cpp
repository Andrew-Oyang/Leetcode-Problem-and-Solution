class Solution {
public:
	// 加减乘除等数学计算返回一个数的题目：首先考虑取值范围(数据类型)的问题，考虑INT_MIN, INT_MAX, 0, -1, 1等特殊情况
	// 例如本题指出超过int的取值范围[-2^31, 2^31-1]的范围则返回2^31-1
	// 另外，要运用 函数抽象 的思维方式，分离题目为 特殊情况 + 运算情况 2部分进行思考
    int divide(int dividend, int divisor) {
		// 被除数等于0，则根据题意应返回0
        if (dividend == 0) return 0;
		// 若被除数等于1，则返回除数即可
        if (divisor == 1) return dividend;
		// 若被除数等于-1，则需要考虑特殊情况，即 INT_MIN / -1 > INT_MAX，超过了整数的取值范围
		// 运用Linux就近处理，出错返回的思想，有如下return的情况就可以简化代码(不用写else, 简单逻辑可以写在一行)
        if (divisor == -1) {
            if (dividend > INT_MIN) return -dividend;
            return INT_MAX;
        }
		// 实际计算过程中，如果有边界情况出现，那么二分法有可能过程中的临时变量超过[INT_MIN, INT_MAX]范围
		// 若超过int范围，则需要将计算用的临时变量改为long型
        long a = dividend;
        long b = divisor;
        int sign = 1;
		// 判断返回数的 符号
		if ((a > 0 && b < 0) || (a < 0 && b > 0)) sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = div(a, b);
        if(sign > 0) return res > INT_MAX ? INT_MAX : res;
        return -res;
     }
	 // 抽象出计算使用的递归函数
	 // 原理：
	 // tb = b;
	 // (b + b) > a ? count = 2 * count (反复)
	 // 条件不满足的话，则返回这部分的计算结果，加递归地对剩下的部分进行相同计算的过程
	 // 最后用递归的方法相加所有的计算结果即为所求
     int div(long a, long b) {
         if (a < b) return 0;
		 long count = 1;
		 long tb = b;
		 while (tb + tb <= a) {
			 count += count;
			 tb += tb;
		 }
		 return count + div(a-tb, b);
     }
};
