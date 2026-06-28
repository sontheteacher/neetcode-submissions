class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum == target) return {1 + start, 1 + end};
            if (sum < target) ++start;
            else --end;
        }
        return {};
    }
};
