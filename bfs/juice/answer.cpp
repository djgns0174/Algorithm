#include<iostream>
using namespace std;

int n, m;
int graph[1001][1001];

bool dfs(int x, int y){
    if( x<=-1 || y<=-1 || x>=n || y>=m){
        return false;
    }

    if(graph[x][y] == 0){
        graph[x][y] = 1;
        dfs(x-1, y);
        dfs(x+1, y);
        dfs(x, y-1);
        dfs(x, y+1);
        return true;
    }

    return false;
}

int main(void){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string input;
        cin >> input;
        for(int j=0; j<m; j++){
            graph[i][j] = input[j] - '0';
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dfs(i, j)) { result++; }
        }
    }

    cout << result << endl;
}