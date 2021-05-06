class Solution {
public:
    string maximumBinaryString(string binary) {
        int one = 0, zero = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0')
                zero++;
            else if (zero == 0) one++;
            binary[i] = '1';
        }
        if (one < binary.size())
            binary[one + zero - 1] = '0';
        return binary;
    }
};