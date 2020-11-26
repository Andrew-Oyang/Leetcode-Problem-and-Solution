class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int cnt = 1;
		int cap = 0;
		for (int i=0; i<flowerbed.size();i++) {
			if (flowerbed[i]==1) {
				cap += (cnt-1)/2;
				cnt=0;
				continue;
			}
			cnt++;
		}
		cnt++;
		cap+=(cnt-1)/2;
		return (n<=cap)?true:false;
    }
};
