#include<iostream>
using namespace std;
int main(void){
    int n;
    cin >> n;

    int answer = 0 ;
    while(n >= 0){
        if(n%5 == 0){
            answer += n/5;
            cout << answer << endl;
            return 0;
        }
        n -= 3;
        answer++ ;
    }

    cout << -1 << endl;
    return 0;
}