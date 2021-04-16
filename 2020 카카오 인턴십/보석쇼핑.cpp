#include <string>
#include <vector>
#include <map>

using namespace std;


vector<int> solution(vector<string> gems) {
	vector<int> answer;
	map<string, int> m;
	int gem_size = gems.size();
	for (int i = 0; i < gem_size; i++) {
		if (m[gems[i]] == 0)
			m[gems[i]]++;
	}
	int gem_kind = m.size();
	m.clear();

	int left,right;
	int ans_left = 0, ans_right = 0;
	int distance = gem_size;
	left = right = 0;
	m[gems[0]]++;
	while (right < gem_size) {
		if (m.size() == gem_kind) {
			if (distance > right - left) {
				distance = right - left;
				ans_left = left + 1;
				ans_right = right + 1;
			}
			m[gems[left]]--;
			if (m[gems[left]] == 0) m.erase(gems[left]);
			left++;
		}
		else {
			right++;
			if (right >= gem_size) continue;
			m[gems[right]]++;
		}
	}
	answer.push_back(ans_left);
	answer.push_back(ans_right);
	return answer;
}

int main() {
	vector<string> gems = { "DIA", "RUBY","RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	vector<int> ans = solution(gems);
	printf("%d %d\n", ans[0], ans[1]);
}