#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	vector<long long> timeStart;
	vector<long long> timeSize;
	for (int i = 0; i < lines.size(); i++) {
		long long sizeL = 0;;
		string lenth = "";
		string size = "";
		for (int j = 11; j <= 12; j++) {
			char a = lines[i][j];
			if ('0' <= a && a <= '9') {
				lenth += a;
			}
		}
		long long changeNumC = stoll(lenth);
		changeNumC = 3600 * changeNumC * 1000;
		sizeL += changeNumC;
		lenth = "";
		for (int j = 14; j <= 15; j++) {
			char a = lines[i][j];
			if ('0' <= a && a <= '9') {
				lenth += a;
			}
		}
		long long changeNumM = stoll(lenth);
		changeNumM = 60 * changeNumM * 1000;
		sizeL += changeNumM;
		lenth = "";
		for (int j = 17; j <= 18; j++) {
			char a = lines[i][j];
			if ('0' <= a && a <= '9') {
				lenth += a;
			}
		}
		long long changeNumS = stoll(lenth);
		changeNumS = changeNumS * 1000;
		sizeL += changeNumS;
		lenth = "";
		for (int j = 20; j <= 22; j++) {
			char a = lines[i][j];
			if ('0' <= a && a <= '9') {
				lenth += a;
			}
		}
		long long changeNumMS = stoll(lenth);
		changeNumMS = changeNumMS;
		sizeL += changeNumMS;
		lenth = "";
		for (int j = 24; j < lines[i].size(); j++) {
			char a = lines[i][j];
			if (('0' <= a && a <= '9') || '.') {
				size += a;
			}
		}
		timeStart.push_back(sizeL);
		double sizeD = stod(size) * 1000;
		long long sizeS = sizeD;
		timeSize.push_back(sizeL - sizeS + 1);
	}

	for (int i = 0; i < lines.size(); i++) {
		int max = 1;
		for (int j = i; j < lines.size(); j++) {
			if (i == j) continue;
			if (timeStart[i] >= timeSize[j]) {
				max++;
			}
			else if (timeStart[i] + 1000 > timeSize[j]) {
				max++;
			}
		}
		if (max > answer) {
			answer = max;
		}
	}
	return answer;
}