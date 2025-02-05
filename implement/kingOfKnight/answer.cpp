#include<iostream>
using namespace std;

int main(){
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {-1, 2, 2, -1, 1, -2, -2, 1};

    string input;
    cin >> input;
    int x = input[0] - 'a' + 1;
    int y = input[1] - '0';

    int result = 0;
    for(int i=0; i<8; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX >= 1 && nextX <= 8 && nextY >= 1 && nextY <= 8) result++;
    }

    cout << result << endl;
}