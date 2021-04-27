#include <algorithm>
#include <vector>
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 1) return "";
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = getLength(s, i, i);
            int len2 = getLength(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        string answer = "";
        for (int i = start; i <= end; i++) {
            answer += s[i];
        }
        return answer;
    }
    int getLength(string s, int start, int end) {
        int L = start;
        int R = end;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};