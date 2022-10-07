#include <stdio.h>
#include <queue>

using namespace std;

#define MAX_N 10
#define MAX_M 10
int N, M;
char Map[MAX_N + 1][MAX_M + 1];
int visited[MAX_N + 1][MAX_M + 1][MAX_N + 1][MAX_M + 1];//��������, �Ķ����� �湮
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
			//���� i �������� ��������
			while (1) {
				flag = 0;
				//���� ����
				//���ۿ� ���� ���
				if (Map[R_ny][R_nx] == 'O') flag = 1;
				//���� �ƴҰ��
				else if (Map[R_ny + dy[i]][R_nx + dx[i]] != '#') {
					//������ġ �Ķ� ������ �Ȱ�ĥ�� �� �� ����
					if ((R_ny + dy[i] != B_ny) || (R_nx + dx[i] != B_nx)) {
						R_ny += dy[i];
						R_nx += dx[i];
					}
					//������ġ ���ļ� �� �� ���
					else {
						flag = 1;
					}
				}
				//���� ��� (�������� ���)
				else {
					flag = 1;
				}

				//�Ķ�����
				//�Ķ������� ���ۿ� ���� ���
				if (Map[B_ny][B_nx] == 'O') flag += 1;
				//���� �ȸ��� ���
				else if (Map[B_ny + dy[i]][B_nx + dx[i]] != '#') {
					//���� ������ ��ġ�� ���� ��� ������
					if ((R_ny != B_ny + dy[i]) || (R_nx != B_nx + dx[i])) {
						B_ny += dy[i];
						B_nx += dx[i];
					}
					//���� ������ ��ĥ ���
					else {
						//��ġ�µ� ���� ������ ���ۿ� ���� ��� �Ķ� ������ ���ۿ� ����
						if (Map[R_ny][R_nx] == 'O') {
							B_ny = R_ny;
							B_nx = R_nx;
						}
						//���ۿ� ������ �ʾҴٸ� �������� ����
						flag += 1;
					}
				}
				//���� ���
				else { flag += 1; }

				//�Ѵ� �������� ���
				if (flag >= 2) break;

			}
			//�Ķ� ������ ���ۿ� �����ٸ� �ȵ�
			if (Map[B_ny][B_nx] == 'O') continue;
			//���� ������ ���ۿ� ���ٸ� ����
			if (Map[R_ny][R_nx] == 'O') return cur.cnt + 1;
			//�ߺ��� ������ ��� �ȵ�
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
	//���� ��ġ ã��
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