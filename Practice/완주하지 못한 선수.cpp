#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	map<string, int> m;
	for (int i = 0; i < participant.size(); i++) {
		m[participant[i]]++;
	}
	for (int i = 0; i < completion.size(); i++) {
		m[completion[i]]--;
		if (m[completion[i]] == 0) m.erase(completion[i]);
	}

	map<string, int>::iterator it = m.begin();
	answer += it->first;
	return answer;
}

int main() {
	vector<string> participant = { "leo", "kiki", "eden" };
	vector<string> completion = { "eden", "kiki" };

	cout << solution(participant, completion) << endl;
}