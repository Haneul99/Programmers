#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int x){
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i<x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    int size = nums.size();
    
    int val = 0;
    for(int i = 0; i < size; i++){
        val = nums[i];
        for(int j = i+1; j < size; j++){
            val += nums[j];
            for(int k = j+1; k < size; k++){
                val += nums[k];
                if(isPrime(val)) answer++;
                val -= nums[k];
            }
            val -= nums[j];
        }
    }


    return answer;
}