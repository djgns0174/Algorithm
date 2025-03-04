#include<iostream>

using namespace std;

int main(void){
    int n;
    cin >> n;

    int answer = -1;

    if(n%3 == 0) {
        answer = n/3;
    }

    int range = n/5;
    for(int i=range; i>0; i--){
        int temp = n - 5*i;
        if(temp%3 == 0){
            answer = i;
            answer += temp/3;
            break;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}