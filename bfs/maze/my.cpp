#include<iostream>

using namespace std;

int main(void){
    int n, m;

    n = 5; m = 6;
    // cin >> n >> m;
    
    // vector<vector<int> > arr(n, vector<int>(m));

    vector<vector<int> > arr = {
        {1, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };



    // for(int i=0; i<n; i++){
    //     string input;
    //     cin >> input;
    //     for(int j=0; j<m; j++){
    //         arr[i][j] = input[j] - '0';
    //     }
    // }

    int result = 1;
    queue<vector<int> > q;
    vector<int> tempArr(3);
    tempArr[0] = 0; tempArr[1] = 0; tempArr[2] = result;
    q.push(tempArr);
    arr[0][0] = 0;

    while(!q.empty()){
        
        int y = q.front()[0];
        int x = q.front()[1];
        int cnt = q.front()[2];

        if(y==n-1 && x==m-1){
            cout << q.front()[2] << endl;
            break;
        }

        q.pop();

        if(y+1 < n && arr[y+1][x] == 1){
            tempArr[0] = y+1; tempArr[1] = x; tempArr[2] = cnt + 1;
            q.push(tempArr);
            arr[y+1][x] = 0;
        } 
        if(y-1 >= 0 && arr[y-1][x] == 1){
            tempArr[0] = y-1; tempArr[1] = x; tempArr[2] = cnt + 1;
            q.push(tempArr);
            arr[y-1][x] = 0;
        } 
        if(x+1 < m && arr[y][x+1] == 1){
            tempArr[0] = y; tempArr[1] = x+1; tempArr[2] = cnt + 1;
            q.push(tempArr);
            arr[y][x+1] = 0;
        } 
        if(x-1 >= 0 && arr[y][x-1] == 1){
            tempArr[0] = y; tempArr[1] = x-1; tempArr[2] = cnt + 1;
            q.push(tempArr);
            arr[y][x-1] = 0;
        }
    }
}