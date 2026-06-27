class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        int res = 0;

        for (int i = 0; i < l; i++) {
            dp[i][i] = 1;
            res++;
        }
        for (int i = 0; i < l - 1; i++) {
            dp[i][i + 1] = s[i] == s[i + 1];
            if (dp[i][i + 1]) {
                cout << i << ", " << i + 1 << endl;
                res++;
            }
        }

        for (int diff = 2; diff < l; diff++) {
            for (int i = 0; i < l - diff; i++) {
                int j = i + diff;
                cout << i << ", " << j;
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                if (dp[i][j]) {
                    res++;
                } 
            }
        }

        return res;
    }
};
