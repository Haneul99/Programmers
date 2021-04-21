#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 1001;
	int size = s.size();
	for (int i = 1; i <= size; i++) {
		vector< pair<int, string> > v;
		int len = 0;
		for (int j = 0; j < size; j += i) {
			string sub = s.substr(j, i);
			if (v.empty()) v.push_back({ 1, sub });
			else {
				if (v[v.size() - 1].second == sub) {
					v[v.size() - 1].first++;
				}
				else v.push_back({ 1,sub });
			}
		}
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first >= 2) {
				int strcnt = to_string(v[j].first).size();
				len += strcnt + v[j].second.size();
			}
			else len += v[j].second.size();
		}
		if (answer > len) answer = len;
	}
	return answer;
}

int main() {
	string s1 = "";
	for (int i = 0; i < 1000; i++) {
		s1 += 'a';
	}
	printf("%d\n", solution(s1));
	string s = "xababcdcdababcdcd";
	printf("%d\n", solution(s));
}

/*
문자열의 개수가 한자리수가 아닐 수 있음. 주의
*/