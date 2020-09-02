#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int maxtime = 0;
    sort(musicinfos.begin(), musicinfos.end());
    for (int i = 0; i < musicinfos.size(); i++) {
        int firstmin = stoi(musicinfos[i].substr(0, 2));
        int firstsec = stoi(musicinfos[i].substr(3, 2));
        int secondmin = stoi(musicinfos[i].substr(6, 2));
        int secondsec = stoi(musicinfos[i].substr(9, 2));
        int time = 0;
        if (firstmin < secondmin) {
            if (firstsec > secondsec) {
                time = (secondmin - firstmin - 1) * 60 + secondsec - firstsec + 60;
            }
            else time = (secondmin - firstmin) * 60 + secondsec - firstsec;
        }
        else time = secondsec - firstsec;
        time += 1;
        size_t first = musicinfos[i].find(',', 12);
        string musictitle = musicinfos[i].substr(12, first - 12);
        string codes = musicinfos[i].substr(first + 1) + " ";
        string code = musicinfos[i].substr(first + 1);
        int codecount = 0;
        size_t check = codes.find('#');
        while (check != string::npos) {
            codecount++;
            check = codes.find('#', check + 1);
        }
        string realcode = "";
        int value = time / (code.size() - codecount);
        int rest = time % (code.size() - codecount);
        for (int j = 0; j < value; j++) {
            realcode += code;
        }
        int restindex = 0;
        for (int j = 0; j < rest; j++) {
            if (code[restindex + 1] != '#') {
                realcode += code[restindex];
                restindex++;
            }
            else {
                realcode += code.substr(restindex, 2);
                restindex += 2;
            }
        }
        size_t search = realcode.find(m);
        while (search != string::npos) {
            if (realcode[search + m.size()] != '#') {
                if (time > maxtime) {
                    maxtime = time;
                    answer = musictitle;
                }
                break;
            }
            search = realcode.find(m, search + 1);
        }
    }
    if (answer.empty()) {
        answer = "(None)";
    }
    return answer;
}