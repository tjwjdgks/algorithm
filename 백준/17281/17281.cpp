#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;
int main() {
	int eling;
	cin >> eling;
	vector<vector<int>> arry;
	int base[3] = { 0,0,0 };
	for (int i = 0; i < eling; i++) {
		vector<int> tempeling;
		for (int j = 0; j < 9; j++) {
			int number;
			cin >> number;
			tempeling.push_back(number);
		}
		arry.push_back(tempeling);
	}
	vector<int> player;
	for (int i = 1; i < 9; i++) {
		player.push_back(i);
	}
	sort(player.begin(), player.end());
	int maxnum = 0;
	do {
		int tempnum = 0;
		deque<int> tempd;
		for (int i = 0; i < player.size(); i++) {
			if (i == 3) {
				tempd.push_back(0);
			}
			tempd.push_back(player[i]);
		}
		int count = 0;
		int playernum = tempd[0];
		int playercount = 0;
		memset(base, 0, sizeof(base));
		for (int i = 0; i < eling; i++) {
			while (count < 3) {
				if (arry[i][playernum] == 0) {
					count++;
				}
				else if (arry[i][playernum] == 1) {
					if (base[2] == 1) {
						tempnum += 1;
						base[2] = 0;
					}
					if (base[1] == 1) {
						base[2] = 1;
						base[1] = 0;
					}
					if (base[0] == 1) {
						base[1] = 1;
						base[0] = 0;
					}
					base[0] = 1;
				}
				else if (arry[i][playernum] == 2) {
					if (base[2] == 1) {
						tempnum += 1;
						base[2] = 0;
					}
					if (base[1] == 1) {
						tempnum += 1;
						base[1] = 0;
					}
					if (base[0] == 1) {
						base[2] = 1;
						base[0] = 0;
					}
					base[1] = 1;

				}
				else if (arry[i][playernum] == 3) {
					if (base[2] == 1) {
						tempnum += 1;
						base[2] = 0;
					}
					if (base[1] == 1) {
						tempnum += 1;
						base[1] = 0;
					}
					if (base[0] == 1) {
						tempnum += 1;
						base[0] = 0;
					}
					base[2] = 1;
				}
				else if (arry[i][playernum] == 4) {
					int tempcount = 0;
					for (int j = 0; j < 3; j++) {
						if (base[j] == 1) {
							tempcount++;
							base[j] = 0;
						}
					}
					tempnum += tempcount + 1;
				}
				playercount++;
				if (playercount == 9)playercount = 0;
				playernum = tempd[playercount];
			}
			memset(base, 0, sizeof(base));
			count = 0;
		}
		maxnum = max(tempnum, maxnum);
	} while (next_permutation(player.begin(), player.end()));
	cout << maxnum;
}