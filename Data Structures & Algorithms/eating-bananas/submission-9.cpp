class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());
        int res = r;
        
        while (l <= r) {
            int m = l + ((r - l) / 2);
            long long hour = 0;
            for (int ban: piles) {
                hour += ceil(double(ban) / m);
            }
            if (hour > h) {
                l = m + 1;
            } else {
                res = m;
                r = m - 1;
            }
        }
        return res;
    }
};
