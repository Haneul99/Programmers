#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int len = moves.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < board[moves[i] - 1].size(); j++) {
			if (board[j][moves[i] - 1] != 0) {
				if (!s.empty()) {
					int pop = s.top();
					if (pop == board[j][moves[i] - 1]) {
						answer += 2;
						s.pop();
					}
					else s.push(board[j][moves[i] - 1]);
				}
				else {
					s.push(board[j][moves[i] - 1]);
				}
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> board = { 
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 3},
		{0, 2, 5, 0, 1},
		{4, 2, 4, 4, 2},
		{3, 5, 1, 3, 1} 
	};
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	printf("%d\n", solution(board, moves));
}