#include<iostream>
using namespace std;

int main(){
    int N, K;
    int answer = 0;
    N = 25;
    K = 4;

    while(1){
        if(N == 1) break;
        answer++;
        if(N%K == 0){
            N = N/K;
            continue;
        }
        N--;
    }

    cout << answer;
    return 0;
}