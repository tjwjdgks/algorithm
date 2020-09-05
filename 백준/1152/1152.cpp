#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	getline(cin, text);
	bool check = false;
	bool textchek = false;
	int answer = 0;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] != ' ') {
			check = true;
			textchek = true;
		}
		if (check == true && text[i] == ' ') {
			if (i != text.size() - 1 && text[i + 1] != ' ') answer++;
		}

	}
	if (textchek) {
		cout << answer + 1;
	}
	else {
		cout << 0;
	}
}