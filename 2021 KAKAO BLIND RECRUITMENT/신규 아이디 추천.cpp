#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
	string answer = "";
	
	for (int i = 0; i < new_id.size(); i++) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')) answer += new_id[i];//소문자 or 숫자인 경우
		else if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
			answer += new_id[i] - 'A' + 'a';
		}//대문자인경우
		else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
			answer += new_id[i];
		}
	}//1, 2단계
	new_id = answer;

	answer = "";
	int dotflag = 0;
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] == '.') {
			if (dotflag == 1);
			else {
				answer += new_id[i];
				dotflag = 1;
			}
		}
		else {
			answer += new_id[i];
			dotflag = 0;
		}
	}//3단계
	new_id = answer;

	if (new_id[0] == '.') new_id.erase(0, 1);
	if (new_id.size() > 0) {
		if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
	}//4단계

	if (new_id.size() == 0) new_id = "a";//5단계

	if (new_id.size() >= 16) {
		new_id = new_id.substr(0, 15);
		if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
	}//6단계


	if (new_id.size() <= 2) {
		while (new_id.size() != 3) {
			new_id.push_back(new_id[new_id.size() - 1]);
		}
	}//7단계

	for (int i = 0; i < new_id.size(); i++) {
		printf("%c", new_id[i]);
	}
	printf("\n\n");

	answer = new_id;
	return answer;
}

int main() {
	//string id = "1111";
	string id = "abcdefghijklmn.p";
	//solution(id);
	printf("%s\n", solution(id));
}

/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/