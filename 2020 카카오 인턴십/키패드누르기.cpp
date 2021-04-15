#include <string>
#include <vector>
#include <math.h>

using namespace std;

int getDistance(int src, int dst){
    int srcX, srcY;
    if(src%3==0) {
        srcX=src/3;
        srcY=3;
    }
    else {
        srcX=src/3 + 1;
        srcY=src%3;
    }
    
    int dstX, dstY;
    if(dst%3==0) {
        dstX=dst/3;
        dstY=3;
    }
    else {
        dstX=dst/3 + 1;
        dstY=dst%3;
    }
    
    return (abs(srcX-dstX) + abs(srcY-dstY));
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left_pos=10;
    int right_pos=12;
    printf("%d\n",numbers.size());
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7) {
            answer+='L';
            left_pos=numbers[i];
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9) {
            answer+='R';
            right_pos=numbers[i];
        }
        else {
            if(numbers[i]==0) numbers[i]=11;
            int leftDist = getDistance(left_pos, numbers[i]);
            int rightDist = getDistance(right_pos, numbers[i]);
            if(leftDist>rightDist) {
                answer+='R';
                right_pos = numbers[i];
            }
            else if(leftDist<rightDist){
                answer+='L';
                left_pos = numbers[i];
            }
            else{
                if(!hand.compare("left")){
                    answer+='L';
                    left_pos = numbers[i];
                }
                else{
                    answer+='R';
                    right_pos = numbers[i];
                }
            }
        }
    }
    
    return answer;
}

/*
1   2  3
4   5  6
7   8  9
10  11  12

1은 1번째 1번째
2는 1번째 2번째
3은 1번째 3번째
4는 2번째 1번째
5는 2번째 2번째
6은 2번째 3번째
7은 3번째 1번째
8은 3번째 2번째
9는 3번째 3번째
10은 4번째 1번째

row와 col의 차의 절댓값 합

1 4 7 10 은 left
3 6 9 12 는 right
2 5 8 0 은 거리가 가까운 것
*/