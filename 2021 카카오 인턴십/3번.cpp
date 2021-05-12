#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> mv;

int makenum() {
	int num = 0;
	int mux = 1;
	while (!mv.empty()) {
		num += mv.top()*mux;
		mv.pop();
		mux *= 10;
	}
	return num;
}

string solution(int n, int k, vector<string> cmd) {
	stack<int> stk;//삭제를 담는 stack

	string answer = "";

	vector<int> arr;
	for (int i = 0; i < n; i++) arr.push_back(0);//삭제되지 않은 상태면 0, 초기화
	
	for (int i = 0; i < cmd.size(); i++) {
		for (int a = 0; a < cmd[i].size(); a++) printf("%c", cmd[i][a]);
		printf("\n");
		if (cmd[i].size() == 1) {
			if (cmd[i] == "C") {
				stk.push(k);
				arr[k] = 1;//삭제된 상태로 바꿔주기
				if (k == n - 1) {
					for (int j = k; j >= 0; j--) {
						if (arr[j] == 0) {
							k = j;
							break;
						}
					}
				}//마지막 원소 삭제한 경우
				else {
					for (int j = k; j < n; j++) {
						if (arr[j] == 0) {
							k = j;
							break;
						}
					}
				}
			}
			else {
				int idx = stk.top();
				stk.pop();
				arr[idx] = 0;//삭제 복구
			}//cmd == "Z"
		}//C, Z
		else {
			for (int j = 2; j < cmd[i].size(); j++) {
				mv.push(cmd[i][j] - '0');
			}
			int x = makenum();
			printf("x: %d\n", x);
			int cnt = 0;

			if (cmd[i][0] == 'U') {
				while (cnt < x) {
					for (int j = k-1; j >= 0; j--) {
						if (arr[j] == 0) {
							cnt++;
							if (cnt == x) k = j;
						}
					}
				}
			}
			else {
				while (cnt < x) {
					for (int j = k + 1; j < n; j++) {
						if (arr[j] == 0) {
							cnt++;
							if (cnt == x) k = j;
						}
					}
				}
			}//Down
		}//U, D
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) answer += 'O';
		else answer += 'X';
	}

	return answer;
}

int main() {
	int n = 8;
	int k = 2;
	vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" };
	//vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
	string answer = solution(n, k, cmd);
	for (int i = 0; i < answer.size(); i++) {
		printf("%c\n", answer[i]);
	}
	printf("\n");
}