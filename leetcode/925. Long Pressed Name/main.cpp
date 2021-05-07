class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameidx = 0;
        bool check = true;
        for (int i = 0; i < typed.size(); i++) {
            if (nameidx == name.size()) {
                if (name[nameidx - 1] == typed[i]) continue;
                check = false;
                break;
            }
            if (name[nameidx] == typed[i]) {
                nameidx++;
            }
            else {
                if (i > 0 && typed[i - 1] == typed[i]) continue;
                check = false;
                break;
            }
        }
        if (nameidx < name.size()) check = false;
        return check;
    }
};