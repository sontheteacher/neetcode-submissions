class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_count;
        int max_freq = 0;
        for (int num : nums) {
            freq_count[num]++;
            max_freq = max(max_freq, freq_count[num]);
        }

        vector<vector<int>> freq(max_freq, vector<int>());
        for (const auto& pp : freq_count) {
            int n = pp.first, fr = pp.second;
            freq[fr - 1].push_back(n);
        }

        int pointer = max_freq - 1;
        int curr = 0;
        vector<int> res(k);
        while (curr < k) {
            for (int num : freq[pointer]) {
                res[curr] = num;
                curr++;
            }
            pointer--;
        }
        return res;
    }
};
