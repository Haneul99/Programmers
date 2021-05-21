#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
	int answer = 0;
	for (int i = left; i <= right; i++) {
		int mod = 1;
		int cnt = 0;
		while (i >= mod) {
			if (i%mod == 0) cnt++;
			mod++;
		}
		if (cnt % 2 == 0) answer += i;
		else answer -= i;
	}
	return answer;
}

int main() {
	int left = 13;
	int right = 17;
	printf("%d\n", solution(left, right));
}