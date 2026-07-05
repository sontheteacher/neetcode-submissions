class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int left_max = height[0], right_max = height[right];
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                left_max = max(left_max, height[left]);
                res += left_max - height[left];
            } else {
                right--;
                right_max = max(right_max, height[right]);
                res += right_max - height[right];
            }
        }
        return res;
    }
};
