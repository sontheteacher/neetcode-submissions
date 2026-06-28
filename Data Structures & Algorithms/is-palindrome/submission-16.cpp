class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int mid = n / 2;
        int i = 0, j = n - 1;
        while (i < j) {
            while ((isspace(s[i]) || !isalnum(s[i])) && i < n)
                ++i;
            while ((isspace(s[j]) || !isalnum(s[j])) && j > -1)
                --j;
            if ((i < j) && tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
        
    }
};
