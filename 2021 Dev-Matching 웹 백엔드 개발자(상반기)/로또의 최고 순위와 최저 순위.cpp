#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	map<int, int> m;
	int cnt = 0;
	for (int i = 0; i < lottos.size(); i++) {
		m[lottos[i]]++;
	}
	for (int i = 0; i < win_nums.size(); i++) {
		int num = win_nums[i];
		if (m[num] > 0) {
			cnt++;
		}
	}
	//맞춘 개수: cnt, 이대로가 가장 낮은 등수
	//cnt + m[0] 이 가장 높은 등수
	if (cnt + m[0] == 6) answer.push_back(1);
	else if (cnt + m[0] == 5) answer.push_back(2);
	else if (cnt + m[0] == 4) answer.push_back(3);
	else if (cnt + m[0] == 3) answer.push_back(4);
	else if (cnt + m[0] == 2) answer.push_back(5);
	else answer.push_back(6);

	if (cnt == 6) answer.push_back(1);
	else if (cnt == 5) answer.push_back(2);
	else if (cnt == 4) answer.push_back(3);
	else if (cnt == 3) answer.push_back(4);
	else if (cnt == 2) answer.push_back(5);
	else answer.push_back(6);

	return answer;
}

int main() {
	vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
	vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
	vector<int> answer = solution(lottos, win_nums);
	printf("%d\t%d", answer[0], answer[1]);
}