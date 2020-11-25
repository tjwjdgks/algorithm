#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N;
int W[20][20];
int dp[20][1 << 17];
int choose[20][1 << 17];

int tsp(int node, int visited) {
	if (visited == ((1 << N) - 1)) {
		if (W[node][1] != 0)
			return W[node][1];
	}

	int& ret = dp[node][visited];
	if (ret != 0) return ret;
	ret = 20000000;

	for (int i = 1; i <= N; i++) {
		if (!(visited & (1 << (i - 1))) && W[node][i] != 0) {
			if (ret > W[node][i] + tsp(i, visited | (1 << (i - 1)))) {
				ret = W[node][i] + tsp(i, visited | (1 << (i - 1)));

				choose[node][visited] = i; // 현재상태에서 다음 상태로가는 노드 번호 저장
			}
		}
	}

	return ret;
}

void reconstruct(int node, int visited) // 처음부터 최적 상태 따라가면서 노드 출력
{
	if (node == -1) return;
	printf("%d ", node);
	int nextNode = choose[node][visited];
	reconstruct(nextNode, visited | 1 << nextNode - 1);
}

int main() {
	scanf("%d", &N);
	memset(choose, -1, sizeof choose);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &W[i][j]);

	printf("%d\n", tsp(1, 1));
	reconstruct(1, 1);
	return 0;
}