#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int areaArray = 0;
    vector<int> sizeArray;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0) {
                int sizeNum = 0;
                int tempNum = picture[i][j];
                queue<pair<int, int>> temp;
                temp.push(make_pair(i, j));
                while (!temp.empty()) {
                    int indexy = temp.front().first;
                    int indexx = temp.front().second;
                    picture[indexy][indexx] = 0;
                    temp.pop();
                    sizeNum++;
                    for (int i = 0; i < 4; i++) {
                        int tempy = indexy + y[i];
                        int tempx = indexx + x[i];
                        if (tempx >= 0 && tempy >= 0 && tempy < m && tempx < n) {
                            if (picture[tempy][tempx] == tempNum) {
                                picture[tempy][tempx] = 0;
                                temp.push(make_pair(tempy, tempx));
                            }
                        }
                    }
                }
                sizeArray.push_back(sizeNum);
                areaArray++;
            }
        }
    }
    if (!sizeArray.empty()) {
        sort(sizeArray.begin(), sizeArray.end(), greater<int>());
        max_size_of_one_area = sizeArray[0];
    }
    else max_size_of_one_area = 0;
    number_of_area = areaArray;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}