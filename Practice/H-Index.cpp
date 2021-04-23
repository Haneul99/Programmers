#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	int size = citations.size();
	for (int i = 0; i <= size; i++) {
		int over = 0;//i회 이상 인용된 논문의 수
		for (int j = 0; j < size; j++) {
			if (citations[j] >= i) over++;
		}
		if (over >= i) answer = i;
	}
	return answer;
}
