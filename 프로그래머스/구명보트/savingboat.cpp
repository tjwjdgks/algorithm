    #include<iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <deque>
    using namespace std;

    int solution(vector<int> people, int limit) {
        int answer = 0;
        sort(people.begin(), people.end(),greater<int>());
        int start = 0;
        int end = people.size()-1;
        for (int i = start; i <=end; i++) {
            int sum = people[i];
            int j = end;
            for (j; j >= start; j--) {
                if (sum + people[j] <= limit) {
                    sum += people[j];
                    end -= 1;
                }
                else {
                    break;
                }
            }
            start += 1;
            answer += 1;
        }
        return answer;
    }
    int main() {
        int start = 0;
        int end = 5;
        int a = solution({ 70,50,80,50 }, 100);
        cout << a;
    }