#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<float, int>a, pair<float, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}//return이 false 면 swap 그러니까 a.first 가 b.first보다 크면 swap 내림차순 정렬

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int sum = stages.size();
	sort(stages.begin(), stages.end());
	int cnt = 0;
	int nowStage = 1;
	int maxStage = stages[stages.size() - 1];
	int numcnt[501] = { 0, };
	
	vector< pair<float, int> > failRate;

	for (int i = 0; i < stages.size(); i++) {
		numcnt[stages[i]]++;
	}

	for (int i = 1; i <= N; i++) {
		float rate;
		if (maxStage >= i) {
			rate = (float)numcnt[i] / sum;
			sum -= numcnt[i];
			failRate.push_back({ rate,i });
		}//도전한 유저가 있는 경우
		else failRate.push_back({ 0.0,i });
	}

	sort(failRate.begin(), failRate.end(), compare);

	for (int i = 0; i < N; i++) {
		answer.push_back(failRate[i].second);
	}
	return answer;
}

int main() {
	//int N = 5;
	//vector<int> stages = { 2,1,2,6,2,4,3,3 };

	int N = 4;
	vector<int> stages = { 4,4,4,4,4 };
	solution(N, stages);
}

/*
실패율 = 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

1 <= N <= 500, 스테이지의 수
1 <= stages <= 200000
각 스테이지에는 1 이상 N+1 이하의 자연수 // 사용자가 도전 중인 스테이지의 번호. N+1 = N번째 스테이지까지 클리어 한 사용자

실패율이 같은 경우 작은 번호의 스테이지가 먼저
유저가 없는 경우 0
*/