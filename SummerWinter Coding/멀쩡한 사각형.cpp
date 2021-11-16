#include <stdio.h>
#include <math.h>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    double grad = (-1) * h / (double)w ;
    
    for(int i = 1;i < w; i++){
        double value = grad * i + h;
        answer += int(floor(value));
    }
    answer *= 2;
    return answer;
}