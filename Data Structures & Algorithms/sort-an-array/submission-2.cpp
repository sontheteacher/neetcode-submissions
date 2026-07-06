class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2; // prevent overflow
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        // now the 2 halves are sorted,
        // we merge them

        vector<int> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); ++k) {
            nums[l + k] = temp[k];
        }
        return;
    }
};