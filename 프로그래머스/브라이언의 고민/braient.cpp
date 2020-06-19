#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <vector>
using namespace std;

string solution(string sentence) {
	string answer = "";
	list<char> ans;
	int two = 0;
	set<char> s;
	set<char> duplicate;
	queue<pair<int, char>> q;
	list<pair<int, int>> l;

	l.push_back(make_pair(-1, -1));

	for (int i = 0; i < sentence.length(); i++) {
		char c = sentence[i];
		if (c == ' ')
			return "invalid";
		if (c >= 'a' && c <= 'z') {
			if (s.find(c) == s.end()) {
				q.push(make_pair(i, c));
				s.insert(c);
			}
		}
	}

	while (!q.empty()) {
		char c = q.front().second;
		int start = q.front().first;
		q.pop();
		int end = start;
		int count = 0;

		if (duplicate.find(c) == duplicate.end())
			duplicate.insert(c);
		else
			return "invalid";

		vector<int> pos;
		for (int i = start; i < sentence.length(); i++) {
			if (sentence[i] == c) {
				if (pos.size() > 0) {
					if (i - pos.back() == 1)
						return "invalid";
				}
				pos.push_back(i);
				end = i;
			}
		}

		if (l.size() > 1) {
			if (abs(start - l.back().first) == 1 || abs(l.back().second - end) == 1)
				return "invalid";
		}

		if (pos.size() == 2 && two < 1) {
			l.push_back(make_pair(start, end));
			for (int j = start + 1; j < end; j++) {
				if (sentence[j] >= 'a' && sentence[j] <= 'z') {
					two = 2;
					break;
				}
				ans.push_back(sentence[j]);
				count++;
			}
			if (two < 1)
				ans.push_back(' ');
			else {
				for (int j = 0; j < count; j++)
					ans.pop_back();
			}
		}
		else {
			if (two > 0) {
				if (sentence[pos.back() + 2] != sentence[l.back().second])
					return "invalid";
				if (sentence[pos.front() - 2] != sentence[l.back().first])
					return "invalid";
			}

			if (start - 1 <= l.back().second && two < 1)
				return "invalid";
			else {
				if (pos.size() == 1) {
					if (pos.front() == 0 || pos.front() == sentence.length() - 1)
						return "invalid";

				}
				else {
					for (int j = 0; j < pos.size() - 1; j++) {
						if (pos[j + 1] - pos[j] != 2)
							return "invalid";
					}
					if (pos.front() == 0 || pos.back() == sentence.length() - 1)
						return "invalid";
				}

				start = start - 1;
				end = end + 1;

				if (two < 1)
					l.push_back(make_pair(start, end));
				for (int j = start; j <= end; j += 2) {
					if (sentence[j] >= 'a' && sentence[j] <= 'z')
						return "invalid";
					else {
						ans.push_back(sentence[j]);
						count++;
					}
				}
				ans.push_back(' ');
			}
		}
		list<pair<int, int>>::iterator iter1 = l.end();
		list<char>::iterator iter2 = ans.end();
		iter1--;
		iter1--;
		int prevEnd = (*iter1).second + 1;

		if (prevEnd < start && two != 1) {
			if (two < 1) {
				for (int i = 0; i <= count; i++)
					iter2--;
			}
			for (int i = prevEnd; i < start; i++)
				ans.insert(iter2, (sentence[i]));
			ans.insert(iter2, ' ');
		}

		if (two > 0)
			two--;
	}
	int prevEnd = l.back().second + 1;
	if (prevEnd < sentence.length()) {
		for (int i = prevEnd; i < sentence.length(); i++)
			ans.push_back(sentence[i]);
	}
	else
		ans.pop_back();

	for (char c : ans)
		answer += c;
	return answer;
}