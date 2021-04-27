class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while (x != 0) {
            int first = x % 10;
            x /= 10;
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && first > 7)) return 0;
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && first < -8)) return 0;
            reverse = reverse * 10 + first;
        }
        return reverse;
    }
};