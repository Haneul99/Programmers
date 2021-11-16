#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> vocab;
    
    string lastWord = words[0];
    vocab.insert(lastWord);
    bool flag = false;
    for(int i=1;i<words.size();i++){
        if(vocab.count(words[i]) || lastWord[lastWord.size() - 1] != words[i][0] || words.size() == 1) {
            answer.push_back(i%n + 1);
            answer.push_back(i/n + 1);
            flag = true;
            break;
        }
        vocab.insert(words[i]);
        lastWord = words[i];
    }
    if(!flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}