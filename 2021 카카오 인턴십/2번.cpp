#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

pair<int, int> start;

int getDist(int x, int y) {
	return abs(start.first - x) + abs(start.second - y);
}


int BFS(int x, int y, vector<string> room) {
	int visit[5][5] = { 0, };
	queue< pair<int, int> > que;
	que.push({ x,y });
	while (!que.empty()) {
		pair< int, int> p = que.front();
		que.pop();
		if (room[p.first][p.second] == 'P' && p != start) return 0;
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && room[nx][ny] != 'X') {
				if (getDist(nx, ny) <= 2 && visit[nx][ny] == 0) {
					que.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
	}
	return 1;
}


vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int k = 0; k < 5; k++) {
		int flag = 1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (places[k][i][j] == 'P') {
					start.first = i;
					start.second = j;
					flag = flag && BFS(i, j, places[k]);
				}
			}//row
		}//col	
		answer.push_back(flag);
	}//����

	return answer;
}



int main() {
	vector<vector<string>> places = { 
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, 
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
	};

	vector<int> answer = solution(places);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", answer[i]);
	}
}