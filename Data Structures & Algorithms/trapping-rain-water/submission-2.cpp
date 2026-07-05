class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int res = 0;
       vector<int> left_max(n, 0);
       vector<int> right_max(n, 0);
       for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
            right_max[n - i - 1] = max(right_max[n - i], height[n - i]);
       }
        for (int i = 1; i < n - 1; ++i) {
            res += max(0, min(left_max[i], right_max[i]) - height[i]);
        }
        return res;
    }
};
