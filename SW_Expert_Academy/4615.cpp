#include<iostream>
#include<vector>

using namespace std;

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

int N, M;

vector<vector<int>>arr;

bool is_out(int x, int y) // 범위 밖인지 판별하는 함수
{
    if(x >= N || y >= N || x < 0 || y < 0)
    {
        return true;
    }

    return false;
}

void dfs(int x, int y, int color, int dir_x, int dir_y, int depth) // 현재 위치 x, 현재 위치 y  착수한 돌의 색상, 방향 x, 방향 y, 재귀 깊이 
{   
    if(is_out(x, y)) return; //범위 나갔으면 return

    int cur_color = arr[y][x]; //현재 위치에서의 색상

    if(cur_color == 0) return;

    if(depth == 1 && color == cur_color) // 바로 옆에 있는 돌은 같은색상이면 안됨
    {
        return;
    }

    if(depth >= 2)
    {
        if(color == cur_color)
        {
            int cnt = depth;
            int cp_x = x; int cp_y = y;
            while(cnt > 0)
            {
                arr[cp_y][cp_x] = color;
                cp_x -= dir_x;
                cp_y -= dir_y;
                cnt--;
            }
            return;
        }
    }

    dfs(x+dir_x, y+dir_y, color, dir_x, dir_y, depth+1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    vector<pair<int,int>>answers;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;

        vector<vector<int>>input;

        for(int i=0; i<M; i++) //입력받기
        {
            vector<int> input_arr(3, 0);
            cin >> input_arr[0] >> input_arr[1] >> input_arr[2];

            input_arr[0] -= 1;
            input_arr[1] -= 1;

            input.push_back(input_arr);
        }

        arr = vector<vector<int>>(N, vector<int>(N, 0)); // 초기 배열 세팅

        int center = (N-1)/2;
        arr[center][center] = arr[center+1][center+1] = 2;
        arr[center][center+1] = arr[center+1][center] = 1;

        for(int i=0; i<M; i++)
        {
            int x = input[i][0];
            int y = input[i][1];
            int color = input[i][2];

            arr[y][x] = color;

            for(int j=0; j<8; j++)
            {
                dfs(x+dx[j], y+dy[j], color, dx[j], dy[j], 1);
            }
        }

        int black = 0; 
        int white = 0;
        for(int i=0; i<N; i++) // 흑,백 개수 저장
        {
            for(int j=0; j<N; j++)
            {
                if(arr[i][j] == 1) black++;
                else if(arr[i][j] == 2) white++;
            }
        }

        answers.push_back({black, white});
	}

    for(int i=0; i<answers.size(); i++) //정답 출력
        cout << "#" << i+1 << " " << answers[i].first << " " << answers[i].second << endl;

	return 0;
}