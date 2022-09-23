#include <string>
#include <vector>
#include <map>

using namespace std;

int score[8] = {0,3,2,1,0,1,2,3};
map<char, int> result;

//RT CF JM AN

string decideTendency() {
    string ans = "";
    if(result['R'] >= result['T']) ans += "R";
    else ans += "T";
    
    if(result['C'] >= result['F']) ans += "C";
    else ans += "F";
    
    if(result['J'] >= result['M']) ans += "J";
    else ans += "M";
    
    if(result['A'] >= result['N']) ans += "A";
    else ans += "N";
    
    return ans;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i=0;i<survey.size();i++) {
        char tendency;
        if(choices[i] >= 5) tendency = survey[i][1];
        else tendency = survey[i][0];       
        result[tendency] += score[choices[i]];
    }
    
    answer = decideTendency();
    return answer;
}