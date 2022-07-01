#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int visit[20002] = {0,};
    vector<int> nodes[20002];
    
    for(int i=0;i<edge.size();i++) {
        nodes[edge[i][0]].push_back(edge[i][1]);
        nodes[edge[i][1]].push_back(edge[i][0]);
    }
    visit[1] = 1;
    
    queue<pair<int, int>> q;//node num, cnt
    q.push({1, 0});
    
    while(!q.empty()) {
        int node = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=0;i<nodes[node].size();i++) {
            int connectedNode = nodes[node][i];
            if(visit[connectedNode] == 0) {
                q.push({connectedNode, cnt+1});
                visit[connectedNode] = cnt + 1;
            }
        }
    }

    int maxValue = 0;
    for(int i=1;i<=n;i++) {
        if(maxValue < visit[i]) {
            maxValue = visit[i];
            answer = 1;
        }
        else if(maxValue == visit[i]) {
            answer++;
        }
    }
    
    return answer;
}