#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	int map1[17][17] = { 0, };
	int map2[17][17] = { 0, };

	for (int i = 0; i < n ; i++) {
		int t = arr1[i];
		int cnt = 0;
		while (t >= 1) {
			cnt++;
			map1[i][n - cnt] = t % 2;
			t /= 2;
		}
	}

	for (int i = 0; i < n; i++) {
		int t = arr2[i];
		int cnt = 0;
		while (t >= 1) {
			cnt++;
			map2[i][n - cnt] = t % 2;
			t /= 2;
		}
	}

	for (int i = 0; i < n; i++) {
		string ans = "";
		for (int j = 0; j < n; j++) {
			if (map1[i][j] == 1 || map2[i][j] == 1) {
				ans += '#';
			}
			else ans += ' ';
		}
		answer.push_back(ans);
	}

	return answer;
}

int main() {
	int n = 5;
	vector<int> arr1 = { 9,20,28,18,11 };
	vector<int> arr2 = { 30,1,21,17,28 };
	solution(n, arr1, arr2);
}

/*
지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.
전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 "지도 1"과 "지도 2"라고 하자. 지도 1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. 지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
"지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.
암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열이다.

숫자배열 두개를 이진수로 변환
하나라도 1이면 1

9 = 01001
*/