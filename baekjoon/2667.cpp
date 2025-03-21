#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 25

using namespace std;

int n;
int arr[MAX][MAX];
bool visited[MAX][MAX];


int func(int startY, int startX){
    int cnt = 1;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};

    queue<pair<int, int> >q;
    
    q.push({startX, startY});
    visited[startY][startX] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(arr[ny][nx] == 1 && !visited[ny][nx]){
                q.push({nx, ny});
                visited[ny][nx] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main(void){

    vector<int>homes;

    cin >> n;

    //입력받기
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<n; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    //visit초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                homes.push_back(func(i, j));
            }
        }
    }

    //정렬
    sort(homes.begin(), homes.end());

    //결과 출력
    cout << homes.size() << endl;
    for(int i=0; i<homes.size(); i++){
        cout << homes[i] << endl;
    }
    
    return 0;
}