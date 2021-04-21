#include <string>

using namespace std;



int solution(string dartResult) {
	int answer = 0;
	int score[4] = { 0, };
	int now = 0;
	int num = 0;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
			num = 10;
			now++;
			i++;
		}
		else if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			num = dartResult[i] - '0';
			now++;
		}
		else if (dartResult[i] == 'S') score[now] += num;
		else if (dartResult[i] == 'D') score[now] += num * num;
		else if (dartResult[i] == 'T') score[now] += num * num*num;
		else if (dartResult[i] == '*') {
			score[now] *= 2;
			score[now - 1] *= 2;
		}
		else if (dartResult[i] == '#') {
			score[now] *= -1;
		}
	}

	answer += score[1] + score[2] + score[3];
	return answer;
}

int main() {
	string dartResult = "1T2D3D#";
	printf("%d\n", solution(dartResult));
}