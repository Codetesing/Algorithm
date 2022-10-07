#include <stdio.h>
#include <queue>

using namespace std;

#define MAX_N 10
#define MAX_M 10
int N, M;
char Map[MAX_N + 1][MAX_M + 1];
int visited[MAX_N + 1][MAX_M + 1][MAX_N + 1][MAX_M + 1];//빨간구슬, 파란구슬 방문
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

typedef struct s {
	int by, bx, ry, rx, cnt;
}CO;

queue<CO> q;

int bfs(int by, int bx, int ry, int rx) {
	CO cur = { by,bx,ry,rx,0 };
	visited[ry][rx][by][bx] = 1;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front(); q.pop();
		if (cur.cnt >= 10) return -1;
		for (int i = 0; i < 4; i++) {
			int R_ny = cur.ry;
			int R_nx = cur.rx;
			int B_ny = cur.by;
			int B_nx = cur.bx;
			int flag = 0;
			//구슬 i 방향으로 굴려보기
			while (1) {
				flag = 0;
				//빨간 구슬
				//구멍에 들어갔을 경우
				if (Map[R_ny][R_nx] == 'O') flag = 1;
				//벽이 아닐경우
				else if (Map[R_ny + dy[i]][R_nx + dx[i]] != '#') {
					//구슬위치 파란 구슬과 안겹칠때 갈 수 있음
					if ((R_ny + dy[i] != B_ny) || (R_nx + dx[i] != B_nx)) {
						R_ny += dy[i];
						R_nx += dx[i];
					}
					//구슬위치 겹쳐서 못 갈 경우
					else {
						flag = 1;
					}
				}
				//벽일 경우 (못움직일 경우)
				else {
					flag = 1;
				}

				//파란구슬
				//파란구슬이 구멍에 빠질 경우
				if (Map[B_ny][B_nx] == 'O') flag += 1;
				//벽에 안막힐 경우
				else if (Map[B_ny + dy[i]][B_nx + dx[i]] != '#') {
					//빨간 구슬과 겹치지 않을 경우 굴러감
					if ((R_ny != B_ny + dy[i]) || (R_nx != B_nx + dx[i])) {
						B_ny += dy[i];
						B_nx += dx[i];
					}
					//빨간 구슬과 겹칠 경우
					else {
						//겹치는데 빨간 구슬이 구멍에 들어갔을 경우 파란 구슬도 구멍에 빠짐
						if (Map[R_ny][R_nx] == 'O') {
							B_ny = R_ny;
							B_nx = R_nx;
						}
						//구멍에 빠지지 않았다면 움직이지 못함
						flag += 1;
					}
				}
				//벽일 경우
				else { flag += 1; }

				//둘다 못움직일 경우
				if (flag >= 2) break;

			}
			//파란 구슬이 구멍에 빠졌다면 안됨
			if (Map[B_ny][B_nx] == 'O') continue;
			//빨간 구슬이 구멍에 들어갔다면 종료
			if (Map[R_ny][R_nx] == 'O') return cur.cnt + 1;
			//중복된 상태일 경우 안됨
			if (visited[R_ny][R_nx][B_ny][B_nx]) continue;
			visited[R_ny][R_nx][B_ny][B_nx] = 1;
			CO tmp = { B_ny, B_nx, R_ny, R_nx, cur.cnt + 1 };
			q.push(tmp);


		}

	}
	return -1;
}


int solve() {
	int ret = 0;
	int ry = 0, rx = 0, by = 0, bx = 0;
	//구슬 위치 찾기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 'R') {
				ry = i;
				rx = j;
			}
			else if (Map[i][j] == 'B') {
				by = i;
				bx = j;
			}
		}
	}
	ret = bfs(by, bx, ry, rx);
	return ret;

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", Map[i]);
	}
	int ans = solve();
	printf("%d", ans);
}