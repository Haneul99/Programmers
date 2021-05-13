#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int total = brown + yellow;
	for(int n=1;n<total;n++){
		if (total % n == 0) {
			int m = total / n;
			if (n < m) continue;
			if (2 * (n + m - 2) == brown) {
				answer.push_back(n);
				answer.push_back(m);
				return answer;
			}
		}
	}

	return answer;
}

int main() {
	int brown = 24;
	int yellow = 24;
	vector<int> answer = solution(brown, yellow);
	printf("%d\t%d\n", answer[0], answer[1]);
}

/*
a * b 
brown = 2a + 2b - 4 = 2(a+b-2)
*/