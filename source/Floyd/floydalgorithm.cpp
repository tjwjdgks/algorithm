#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF 987654321 //무한대  임의의 숫자 지정
using namespace std;
vector<vector<int>> D,W,P;

//TEST 용 함수
void printD(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
//Algorithm 3.4 floyd2
void floyd2(int n, vector<vector<int>> W, vector<vector<int>> &D, vector<vector<int>> &P) {
	int i, j, k; // 순회용 변수
	//P를 n*n의 사이즈로 만들고 -1으로 초기화
	for (i = 0; i < n; i++) {
		vector<int> temp;
		for (j = 0; j <n; j++) {
			temp.push_back(-1);
		}
		P.push_back(temp);
	}
	D = W; // W배열을 copy해 D 배열에 저장

	//floyd2 알고리즘
	
	for (k = 0; k < n; k++) { // 중간노드
		for (i = 0; i < n; i++) { // 시작노드
			for (j = 0; j < n; j++) { // 도착노드
				if (D[i][k] + D[k][j] < D[i][j]) { // 더 짧은 길을 발견한 경우
					P[i][j] = k; // 중간노드 P배열에 저장
					D[i][j] = D[i][k] + D[k][j]; // 최소값을 갱신
				}
			}
		
		}
		//test 용 출력
		cout << k << "번째" << endl;
		cout << "D" << k << endl;
		printD(D);
		cout << "P" << k << endl;
		printD(P);
		cout << endl;
	}
}
//Algorithm 3.5 path
void path(int q, int r) {
	if (P[q][r] != -1) {
		path(q, P[q][r]); // 재귀로 q~ P[q][r]에서 q에 가까운 중간노드를 찾아들어간다
		cout << "v" << P[q][r] << " "; // 노드 출력
		path(P[q][r], r); // 재귀로 P[q][r] ~ r에서 P[q][r]에 가까운 중간노드 찾아들어간다
	}
}
int main() {
	/*
	vector<vector<int>> input = {
		{0,1,INF,1,5}, //V0 순서대로(V0,V1,V2,V3,V4)
		{9,0,3,2,INF},
		{INF,INF,0,4,INF},
		{INF,INF,2,0,3},
		{3,INF,INF,INF,0}
	};
	*/
	
	
	vector<vector<int>> input = {
		{0,5,1}, 
		{INF,0,3},
		{1,2,0}
	};
	int size = input.size();
	floyd2(size, input, D, P);

	cout << "알고리즘 path 부분" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "v" << i << " ";
			path(i, j);
			cout << "v" << j << " ";
			cout << endl;
		}
	}
	
}
