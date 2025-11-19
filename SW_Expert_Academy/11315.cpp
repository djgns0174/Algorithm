#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;

string answer;
vector<vector<int>>arr;

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

bool is_out(int x, int y) // 바둑판의 범위를 넘어가는지
{
    if(x >= N || y >= N || x < 0 || y < 0) return true;

    return false;
}

void dfs(int x, int y, int depth, int dir_x, int dir_y)
{
    if(is_out(x, y)) return; // 바둑판의 범위를 넘어가면 return

    if(arr[y][x] == 0) return; // 오목이 완성되지 않고 중간에 끊기면 return
    
    if(arr[y][x] == 1 && depth == 4) // 오목의 조건을 충족하면
    {
        answer = "YES";
        return;
    }

    dfs(x+dir_x, y+dir_y, depth+1, dir_x, dir_y); // 왔던 방향으로 계속 탐색
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    cin >> T;

    vector<string>answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = "NO";

        cin >> N;
        
        arr = vector<vector<int>>(N, vector<int>(N, 0)); //바둑판

        for(int i=0; i<N; i++) //입력받기
        {
            string input;
            cin >> input;

            for(int j=0; j<N; j++)
            {
                if(input[j] == '.') arr[i][j] = 0;
                else if(input[j] == 'o') arr[i][j] = 1;
            }
        }

        for(int y=0; y<N; y++)
        {
            for(int x=0; x<N; x++)
            {
                if(arr[y][x] == 0) continue; // 바둑알이 존재하는 경우에만 DFS탐색 수행

                // 8개의 방향으로 DFS 탐색
                for(int k=0; k<8; k++) dfs(x+dx[k], y+dy[k], 1, dx[k], dy[k]); 
            }
        }
        
        answers.push_back(answer);
	}

    for(int i=0; i<T; i++) cout << "#" << i+1 << " " << answers[i] << endl;

	return 0;
}