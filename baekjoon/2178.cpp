#include<iostream>
#include<string>
#include<queue>

#define MAX 101

using namespace std;

int main(void){
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    queue<pair<int, int> >q;

    int n, m;
    cin >> n >> m;

    int arr[MAX][MAX];
    int dp[MAX][MAX];
    bool visit[MAX][MAX];

    //입력받기
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        
        for(int j=0; j<m; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    //dp테이블 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dp[i][j] = INT32_MAX;
        }
    }
    dp[0][0] = 1;

    //visit테이블 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visit[i][j] = false;
        }
    }
    
    visit[0][0] = true;
    q.push({0,0});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(!visit[ny][nx] && arr[ny][nx]==1){
                q.push({ny, nx});
                visit[ny][nx] = true;
                if(dp[y][x]+1 < dp[ny][nx]){
                    dp[ny][nx] = dp[y][x]+1;
                }
            }
        }
    }

    cout << dp[n-1][m-1] << endl;
    
    return 0;
}