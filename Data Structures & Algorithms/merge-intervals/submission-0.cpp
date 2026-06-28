class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end()); // sort ascending based on start time
       vector<vector<int>> res;
       int curr_start = intervals[0][0], curr_end = intervals[0][1];
       for (int i = 1; i < intervals.size(); ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            // if (curr_start == 0) {
            //     curr_start = left;
            //     curr_end = max(curr_end, right);
            // }
            if (left <= curr_end) {
                curr_end = max(curr_end, right);
            } else {
                res.push_back({curr_start, curr_end});
                curr_start = left, curr_end = right;
            }
       } 
       res.push_back({curr_start, curr_end});
       return res;
    }
};
