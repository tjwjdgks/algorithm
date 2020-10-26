#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF 987654321 //���Ѵ�  ������ ���� ����
using namespace std;
vector<vector<int>> D,W,P;

//TEST �� �Լ�
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
	int i, j, k; // ��ȸ�� ����
	//P�� n*n�� ������� ����� -1���� �ʱ�ȭ
	for (i = 0; i < n; i++) {
		vector<int> temp;
		for (j = 0; j <n; j++) {
			temp.push_back(-1);
		}
		P.push_back(temp);
	}
	D = W; // W�迭�� copy�� D �迭�� ����

	//floyd2 �˰���
	
	for (k = 0; k < n; k++) { // �߰����
		for (i = 0; i < n; i++) { // ���۳��
			for (j = 0; j < n; j++) { // �������
				if (D[i][k] + D[k][j] < D[i][j]) { // �� ª�� ���� �߰��� ���
					P[i][j] = k; // �߰���� P�迭�� ����
					D[i][j] = D[i][k] + D[k][j]; // �ּҰ��� ����
				}
			}
		
		}
		//test �� ���
		cout << k << "��°" << endl;
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
		path(q, P[q][r]); // ��ͷ� q~ P[q][r]���� q�� ����� �߰���带 ã�Ƶ���
		cout << "v" << P[q][r] << " "; // ��� ���
		path(P[q][r], r); // ��ͷ� P[q][r] ~ r���� P[q][r]�� ����� �߰���� ã�Ƶ���
	}
}
int main() {
	/*
	vector<vector<int>> input = {
		{0,1,INF,1,5}, //V0 �������(V0,V1,V2,V3,V4)
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

	cout << "�˰��� path �κ�" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "v" << i << " ";
			path(i, j);
			cout << "v" << j << " ";
			cout << endl;
		}
	}
	
}
