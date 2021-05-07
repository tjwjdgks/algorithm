class Solution {
public:
    vector<int> arr;
    int targetlength;
    int targetk;
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> answer;
        targetlength = n;
        targetk = k;
        for (int i = 1; i <= 9; i++) {
            getAnswer(i, 1);
        }
        answer = arr;
        return answer;
    }
    void getAnswer(int targetnum, int count) {
        if (count == targetlength) {
            arr.push_back(targetnum);
            return;
        }
        int rest = targetnum % 10;
        if (targetk == 0) {
            getAnswer(targetnum * 10 + (rest - targetk), count + 1);
        }
        else {
            if (rest - targetk >= 0)
                getAnswer(targetnum * 10 + (rest - targetk), count + 1);
            if (rest + targetk < 10)
                getAnswer(targetnum * 10 + (rest + targetk), count + 1);
        }
        return;
    }
};