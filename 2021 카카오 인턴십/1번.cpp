#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

int solution(string s) {
	int answer = 0;
	int size = s.size();

	for (int i = 0; i < size; i++) {
		printf("i: %d\n", i);
		printf("%c\n", s[i]);
		if (s[i] >= '0' && s[i] <= '9') stk.push(s[i] - '0');
		else if (s[i] == 'o') {
			stk.push(1);
			i += 2;
		}
		else if (s[i] == 'e') {
			stk.push(8);
			i += 4;
		}
		else if (s[i] == 'n') {
			stk.push(9);
			i += 3;
		}
		else if (s[i] == 'z') {
			stk.push(0);
			i += 3;
		}
		else if (s[i] == 't') {
			if (s[i + 1] == 'w') {
				stk.push(2);
				i += 2;
			}//two
			else if (s[i + 1] == 'h') {
				stk.push(3);
				i += 4;
			}//three
		}
		else if (s[i] == 'f') {
			if (s[i + 1] == 'o') {
				stk.push(4);
				i += 3;
			}
			else if (s[i + 1] == 'i') {
				stk.push(5);
				i += 3;
			}
		}
		else if (s[i] == 's') {
			if (s[i + 1] == 'i') {
				stk.push(6);
				i += 2;
			}
			else if (s[i + 1] == 'e') {
				stk.push(7);
				i += 4;
			}
		}
	}
	int mux = 1;
	while (!stk.empty()) {
		answer += stk.top()*mux;
		stk.pop();
		mux *= 10;
	}
	return answer;
}

int main() {
	string s = "123";
	printf("%d\n", solution(s));

	
}