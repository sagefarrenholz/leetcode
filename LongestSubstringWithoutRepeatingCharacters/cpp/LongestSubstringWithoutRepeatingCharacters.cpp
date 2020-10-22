class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int8_t len = 1, back = 0, last[256] = { }; last[s[0]]++;    // indexed at 1
        for (int8_t c = 1; c <= s.length(); c++) {
            if (c == s.length() || last[s[c]] > 0) {
                if (c - back > len) len = c - back;
                if (last[s[c]] > back) back = last[s[c]];
            }
            last[s[c]] = c + 1;
        }
        return len;
    }
};
