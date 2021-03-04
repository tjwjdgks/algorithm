#include <stdio.h>
#include <cstring>

struct Dir {
	int x, y, s, d, z;
};

struct Map {
	int shark, index;
};
Map map[100][100];
int main() {
	int R, C, M;
	Dir v[10000];
	scanf("%d %d %d", &R, &C, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &v[i].x, &v[i].y, &v[i].s, &v[i].d, &v[i].z);
		v[i].x--; v[i].y--; v[i].d--;
		if (v[i].d == 0 || v[i].d == 1)
			v[i].s %= ((R - 1) * 2);
		else
			v[i].s %= ((C - 1) * 2);
		map[v[i].x][v[i].y].shark = v[i].z;
		map[v[i].x][v[i].y].index = i;
	}

	int ans = 0;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int k = 0; k < C; k++) {

		for (int j = 0; j < R; j++) {
			if (map[j][k].shark) {
				ans += map[j][k].shark;
				v[map[j][k].index].z = 0;
				map[j][k].shark = 0;
				break;
			}
		}

		memset(map, 0, sizeof(map));
		for (int i = 0; i < M; i++) {
			if (!v[i].z) continue;
			int nd = v[i].d;
			int nx = v[i].x + v[i].s * dx[nd];
			int ny = v[i].y + v[i].s * dy[nd];
			if (nx < 0 || nx >= R) {
				if (nx < 0) {
					if (nx / (R - 1) == 0) { nx = -nx; nd ^= 1; }
					else nx += 2 * (R - 1);
				}
				else {
					if (nx / (R - 1) == 1) { nx = 2 * (R - 1) - nx;	nd ^= 1; }
					else nx -= 2 * (R - 1);
				}
			}
			if (ny < 0 || ny >= C) {
				if (ny < 0) {
					if (ny / (C - 1) == 0) { ny = -ny; nd ^= 1; }
					else ny += 2 * (C - 1);
				}

				else {
					if (ny / (C - 1) == 1) { ny = 2 * (C - 1) - ny; nd ^= 1; }
					else ny -= 2 * (C - 1);
				}
			}

			if (!map[nx][ny].shark)
				map[nx][ny].shark = v[i].z, map[nx][ny].index = i;
			else {
				if (map[nx][ny].shark > v[i].z)
					v[i].z = 0;

				else {
					v[map[nx][ny].index].z = 0;
					map[nx][ny].shark = v[i].z;
					map[nx][ny].index = i;
				}
			}
			v[i].x = nx; v[i].y = ny; v[i].d = nd;
		}
	}
	printf("%d", ans);
	return 0;
}