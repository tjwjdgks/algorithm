#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
	int count = 0;
	int start = 0;;
	int answer = 0;
	string compare = "";
	for (int i = 0; i < name.size(); i++) {
		compare += "A";
	}
	while (compare != name) {
		int next = 0;
		int right = 0;
		int left = 0;
		for (int i = 0; i < name.size(); i++) {
			if (start + i < name.size()) right = start + i;
			else right = start + i - name.size();

			if (start - i >= 0) left = start - i;
			else left = start - i + name.size();

			if (compare[right] != name[right]) next = right;
			else if (compare[left] != name[left]) next = left;
			else continue;

			answer += i;
			answer += min(name[next] - 'A', 'Z' - name[next] + 1);
			compare[next] = name[next];
			break;
		}
		start = next;
	}
}
int main() {
	int a = solution("JAN");
}